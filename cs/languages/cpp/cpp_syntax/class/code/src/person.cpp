#include <iostream>
#include "static.h"
using namespace std;

#include "person.h"

Person::Person(int age)
    : age(age)
{
    cout << "Person arg cntr " << age << endl;
}

Person::Person()
    : age(20)
{
    cout << "Person default cntr" << endl;
    // cout << TestStatic::d1 << endl;
}

Person::Person(const Person &p)
    : age(p.age)
{
    cout << "Person copy cntr " << age << endl;
}

void Person::func2(const Person &p) const
{
    cout << "other age: " << p.age << endl;
}

void Person::func() const
{
    cout << "age: " << age << endl;
}
