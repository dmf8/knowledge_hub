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

void lock()
{
    while (::a.exchange(true))
    {
        cout << "locked 2" << endl;
        continue;
    }

    ::count++;
    ::a.exchange(false);
}

void work(int n)
{
    for (int i = 0; i < n; ++i)
        lock();
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

    return 0;
}