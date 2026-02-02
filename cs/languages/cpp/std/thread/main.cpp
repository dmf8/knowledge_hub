#include <iostream>
#include <set>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;
lock_guard<mutex> *lck = nullptr;

void func1()
{
    lck = new lock_guard<mutex>(mtx);
    for (int i = 0; i < 1000; ++i)
        cout << i << endl;
    delete lck;
    for (int i = 0; i < 1000; ++i)
        cout << i * 10000 << endl;
}

void func2()
{
    lck = new lock_guard<mutex>(mtx);
    for (int i = 0; i < 1000; ++i)
        cout << "abc" << endl;
    delete lck;
}

void func3(int i)
{
    cout << __func__ << ": " << i << endl;
}

void test_lock_guard()
{

    thread t1(&func1);
    thread t2(&func2);

    t1.join();
    t2.join();
}

class TestClass
{
public:
    void func(int i)
    {
        cout << "class function: " << i << endl;
    }

    static void func_s(int i)
    {
        cout << "static member function: " << i << endl;
    }
};

void test_construct()
{
    thread t1(func3, 1);
    thread t2([]
              { cout << __func__ << " lambda" << endl; });
    TestClass tc;
    thread t3(&TestClass::func, &tc, 3);
    thread t4([&tc]
              { tc.func(4); });
    thread t5(&TestClass::func_s, 5);
    thread t6([&tc]
              { tc.func_s(6); });
    thread t7([]
              { TestClass::func_s(7); });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
}

int main()
{
    // snippet lock by lock_guard
    // test_lock_guard();

    // thread construct
    test_construct();

    cout << "finished" << endl;
}