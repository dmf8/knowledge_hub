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

void test_unique()
{
    unique_ptr<TestStruct> p;
    cout << "empty init " << p.operator bool() << endl; // 0
    p = make_unique<TestStruct>();
    cout << "assigned " << p.operator bool() << endl; // 1
    TestStruct *p_raw = p.release();
    p_raw->i = 100;
    cout << "modifid " << p_raw->i << endl;           // 100
    cout << "released " << p.operator bool() << endl; // 0
    p.reset(p_raw);
    cout << "reset " << p.operator bool() << endl; // 1
    cout << "int " << p->i << endl;                // 100
}

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
    // unique_ptr
    test_unique();
    // shared_ptr
    // test_shared();
    return 0;
}