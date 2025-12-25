#include <iostream>
#include "const_obj.h"

using namespace std;

void ConstObj::funcConst() const
{
    // a = 1;
    b = 11;
    cout << "const member function: " << a << " " << b << endl;
}

void ConstObj::func()
{
    a = 2;
    b = 12;
    cout << "non const member function: " << a << " " << b << endl;
}