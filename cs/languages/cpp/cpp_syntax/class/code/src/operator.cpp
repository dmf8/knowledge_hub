#include <iostream>
using namespace std;

#include "operator.h"

Operator operator+(const Operator &o, int n)
{
    Operator temp = o;
    temp.org += n;
    return temp;
}

Operator operator+(int n, const Operator &o)
{
    return o + n;
}

Operator::Operator(int org)
    : org(org)
{
}

Operator Operator::operator+(const Operator &o) const
{
    return *this + o.org;
}

Operator &Operator::operator++()
{
    *this = *this + 1;
    return *this;
}

Operator Operator::operator++(int)
{
    Operator temp = *this;
    *this = *this + 1;
    return temp;
}

void Operator::show() const
{
    cout << "value: " << org << endl;
}

int Operator::getValue() const
{
    return org;
}
