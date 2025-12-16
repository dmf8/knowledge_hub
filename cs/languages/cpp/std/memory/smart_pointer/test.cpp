#include <iostream>
#include <memory>
using namespace std;

struct TestStruct
{
    int i = 10;
    double d = 20;
    void func()
    {
        cout << "TestStruct::func" << endl;
    }
};

void test_shared()
{
    shared_ptr<TestStruct> p = make_shared<TestStruct>();
    cout << "count1: " << p.use_count() << endl; // 1
    p->func();
    {
        shared_ptr<TestStruct> p2 = p;
        cout << "count2: " << p.use_count() << endl; // 2
        p.reset(new TestStruct);
        cout << "count5: " << p.use_count() << endl; // 1
    }
    cout << "count3: " << p.use_count() << endl; // 1

    p.reset();
    cout << "count4: " << p.use_count() << endl; // 0

    cout << "bool " << p << " " << p.operator bool() << endl;
}

int main()
{
    // shared_ptr
    test_shared();
    return 0;
}