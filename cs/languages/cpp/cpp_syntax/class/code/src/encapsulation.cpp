#include <iostream>
using namespace std;

#include "encapsulation.h"

int Encapsulation::i = 6;

Encapsulation::Encapsulation()
{
    cout << __FUNCTION__ << endl;
}

void Encapsulation::defaultParams(int p1, int p2 = 10)
{
    // this function cannot be called outside
    cout << __FUNCTION__ << ": " << p1 << ", " << p2 << endl;
}

void Encapsulation::defaultParams2(int p)
{
    cout << __FUNCTION__ << ": " << p << endl;
}

void Encapsulation::formalParams(int i, double d)
{
    cout << __FUNCTION__ << ": " << i << ", " << d << endl;
}

void Encapsulation::formalParams2(int i, double)
{
    cout << __FUNCTION__ << ": " << i << endl;
}

void Encapsulation::func()
{
    defaultParams(1);
}

void Encapsulation::func() const
{
    cout << __FUNCTION__ << " const" << endl;
}
