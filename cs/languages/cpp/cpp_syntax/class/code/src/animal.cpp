#include <iostream>
using namespace std;

#include "animal.h"

Animal::Animal(const Animal &a)
    : name(a.name)
{
}

void Animal::showName() const
{
    cout << "Animal name: " << name << endl;
}
