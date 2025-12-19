#include <iostream>
using namespace std;

#include "animal.h"

Animal::Animal(const Animal &a)
    : name(a.name),
      type(a.type)
{
}

Animal::Animal(const std::string &name)
    : name(name),
      type(1)
{
}

Animal::Animal()
    // : type(0)
    : claw(Claw{})
{
}

void Animal::showName() const
{
    cout << "Animal name: " << name << endl;
}

Claw::Claw()
    : toes(2),
      count(2)
{
    cout << "Claw default cntr" << endl;
}

Claw::Claw(int toes, int count)
    : toes(toes),
      count(count)
{
    cout << "Claw args cntr" << endl;
}
