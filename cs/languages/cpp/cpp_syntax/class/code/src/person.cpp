#include <iostream>
#include "animal.h"
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

Person::~Person()
{
    cout << "Person destructor" << endl;
}

void Person::func2(const Person &p) const
{
    cout << "other age: " << p.age << endl;
}

void Person::setPet(Animal *a)
{
    this->pet = a;
}

void Person::showPetName() const
{
    cout << "pet name: " << this->pet->name << endl;
}

void Person::showPetType() const
{
    cout << "pet type: " << this->pet->type << endl;
}

void Person::func() const
{
    cout << "age: " << age << endl;
}
