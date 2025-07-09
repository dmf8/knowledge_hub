#include "test_class.h"
#include <iostream>

using namespace std;

TestClass::TestClass()
{
    cout << __FUNCTION__ << endl;
}

void TestClass::func()
{
    cout << __FUNCTION__ << endl;
}