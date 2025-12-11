#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void func()
    {
        cout << "parent" << endl;
    }
};

class Son : public Parent
{
public:
    virtual void func() override
    {
        cout << "son" << endl;
    }
};

void new_son(Parent *&p)
{
    p = new Son();
}

void new_int(int *&p)
{
    p = new int(50);
}

int main()
{
    // reference to object
    int a = 5;
    int &ra = a;
    cout << ra << endl;

    // reference to array
    int arr[2] = {1, 2};
    int (&rarr)[2] = arr;
    cout << rarr[1] << endl;
    typedef int(ARR_REF)[2];
    ARR_REF &rarr2 = arr;
    cout << rarr2[1] << endl;

    // const pointer
    const int *p1 = &a;
    int const *p2 = &a;
    int *const p3 = &a; // equivalent to reference
    // *p1 = 6;
    // *p2 = 7;
    *p3 = 8;
    p1 = &ra;
    p2 = &ra;
    // p3 = &ra;

    // polymorphic
    Parent *parent = nullptr;
    new_son(parent);
    Parent &rp = *parent;
    parent->func();
    rp.func();

    // pointer reference
    int *pi = nullptr;
    new_int(pi);
    cout << *pi << endl;

    return 0;
}