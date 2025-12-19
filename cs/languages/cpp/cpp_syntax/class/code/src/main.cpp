#include <iostream>
#include "animal.h"
#include "person.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "encapsulation.h"
#include "extern_c.h"
#ifdef __cplusplus
}
#endif
using namespace std;

namespace overload
{
    void func()
    {
        cout << __FUNCTION__ << endl;
    }
    void func(int)
    {
        cout << __FUNCTION__ << " int" << endl;
    }
}

void test_parameters()
{
    Encapsulation e;
    // e.defaultParams(1); // error
    e.func();
    e.defaultParams2();
    e.formalParams(1, 1.5);
    e.formalParams2(2, 3.5);
}

void test_overload()
{
    overload::func();
    overload::func(1);

    Encapsulation e;
    e.func();
    const Encapsulation *pe = &e;
    pe->func();
}

void test_class()
{
    Person p1(18);
    Person p2 = Person();
    Person p3;
    Person p4{};
    Person p5{19};
    cout << "---" << endl;
    Person p6{p5};
    Person{p5};
    Person();
    p1.func();
    p2.func();
    p3.func();
    p4.func();
    p5.func();
    p6.func();
    Person *pp1 = new Person(28);
    Person *pp2 = new Person();
    Person *pp3 = new Person;
    Person *pp4 = new Person{29};
    pp1->func();
    pp2->func();
    pp3->func();
    pp4->func();
    pp4->func2(*pp1);
}

void test_class_default()
{
    Animal a;
    a.showName();
}

int main()
{
    // parameters
    // test_parameters();

    // overload
    // test_overload();

    // extern C
    // func();

    // class
    // test_class();

    // default functions
    test_class_default();

    return 0;
}