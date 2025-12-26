#include <iostream>
#include <vector>
#include <memory>
#include "space.h"
#include "const_obj.h"
#include "static.h"
#include "animal.h"
#include "explicit.h"
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
    // Animal cat("cat");
    a.showName();
    // cat.showName();
}

void test_explicit()
{
    TestExplicit te = 2;
}

void test_new()
{
    Person p1{18};
    Person *p2 = new Person{p1};
    p2->func();
    int *p3 = new int{3};
    cout << *p3 << endl;

    int *p_arr = new int[5]{1, 2, 3, 4};
    // for (int i = 0; i < 5; ++i)
    //     p_arr[i] = i;
    for (int i = 0; i < 5; ++i)
        cout << p_arr[i] << endl;

    delete p2;
    delete p3;
    delete[] p_arr;

    unique_ptr<int> up1{new int{30}};
    cout << *up1 << endl;
    vector<unique_ptr<int>> vec;
    vec.push_back(make_unique<int>(60));
    // vec = {
    //     make_unique<int>(60),
    //     make_unique<int>(90),
    // };
    for (int i = 0; i < vec.size(); ++i)
        cout << *vec[i] << endl;

    cout << "--anonymous constructor" << endl;
    Person p4 = Person{100};
    cout << "--anonymous constructor end" << endl;
}

void test_static()
{
    cout << TestStatic::i1 << endl;
    // Person p1;
    TestStatic::func1();
    TestStatic::func2();
}

void test_space()
{
    Space s;
    cout << "empty class: " << sizeof(s) << endl;
}

void test_this()
{
    Space *s = nullptr;
    s->func();
}

void test_const()
{
    ConstObj co;
    co.funcConst();
    co.func();

    const ConstObj co2;
    co2.funcConst();
    // co2.func();
}

namespace friend_test
{
    void seeFriend(Animal *a)
    {
        cout << "see friend " << a->name << endl;
    }
}

void test_friend()
{
    // Animal a{"wangcai"};
    Cat c;
    Person p;
    p.setPet(&c);
    p.showPetName();
    p.showPetType();
    friend_test::seeFriend(&c);
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
    // test_class_default();

    // explicit
    // test_explicit();

    // new/delete
    // test_new();

    // static
    // test_static();

    // space
    // test_space();

    // this
    // test_this();

    // const/mutable
    // test_const();

    // friend
    test_friend();

    return 0;
}