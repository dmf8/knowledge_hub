#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

template <class T>
void exchange(atomic<T> &a, T val)
{
    T old = a.exchange(val);
    cout << "old value: " << old << endl;
}

atomic<bool> a{false};
int count = 0;
int count2 = 0;

void lock()
{
    if (::a.exchange(true, memory_order_relaxed))
    {
        ::count2++;
        return;
    }

    ::count++;
    ::a.exchange(false, memory_order_relaxed);
}

void work(int n)
{
    for (int i = 0; i < n; ++i)
        lock();
}

atomic<bool> ready{false};
atomic<int> data{0};

void producer()
{
    ::data.store(42, memory_order_relaxed);
    ::ready.store(true, memory_order_relaxed);
}

void consumer()
{
    while (!ready.load(memory_order_relaxed))
        this_thread::yield();

    cout << "data: " << data.load(memory_order_relaxed) << endl;
}

atomic_flag f = ATOMIC_FLAG_INIT;
int count_flag = 0;
void spin_test(int n)
{
    for (int i = 0; i < n; ++i)
    {
        while (::f.test_and_set(memory_order_relaxed))
        {
        }
        ::count_flag++;
        ::f.clear(memory_order_relaxed);
    }
}

int main()
{
    // construction
    atomic<bool> a1{false};
    cout << "a1: " << a1.load() << endl;

    // initialize
    atomic<int> a2;
    cout << "uninit a2: " << a2.load() << endl;
    atomic_init(&a2, 5);
    cout << "init a2: " << a2.load() << endl;

    // exchange
    exchange(a1, true);
    exchange(a1, false);

    int count = 1000000;
    thread th1(work, count);
    thread th2(work, count);

    th1.join();
    th2.join();
    cout << "count: " << ::count << endl;
    cout << "count2: " << ::count2 << endl;
    cout << "total count: " << ::count + ::count2 << endl;

    // memory order
    thread th3(producer);
    thread th4(consumer);

    th3.join();
    th4.join();

    // atomic_flag
    atomic_flag f1;
    atomic_flag f2 = ATOMIC_FLAG_INIT;

    cout << f1.test_and_set() << endl;
    cout << f2.test_and_set() << endl;

    thread th5(spin_test, count);
    thread th6(spin_test, count);
    th5.join();
    th6.join();
    cout << "flag test: " << ::count_flag << endl;

    return 0;
}