#include <iostream>
#include "encapsulation.h"
using namespace std;

int main()
{
    Encapsulation e;
    // e.defaultParams(1); // error
    e.func();
    e.defaultParams2();
    e.formalParams(1, 1.5);
    e.formalParams2(2, 3.5);
    return 0;
}