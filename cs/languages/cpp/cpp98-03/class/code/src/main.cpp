#include <iostream>
#include "encapsulation.h"
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

int main()
{
    // parameters
    Encapsulation e;
    // e.defaultParams(1); // error
    e.func();
    e.defaultParams2();
    e.formalParams(1, 1.5);
    e.formalParams2(2, 3.5);

    // overload
    overload::func();
    overload::func(1);

    e.func();
    const Encapsulation *pe = &e;
    pe->func();

    return 0;
}