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

int main()
{
    // snippet lock by lock_guard
    thread t1(&func1);
    thread t2(&func2);

    t1.join();
    t2.join();
    cout << "finished" << endl;
}