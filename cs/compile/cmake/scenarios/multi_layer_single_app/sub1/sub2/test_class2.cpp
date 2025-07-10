#include "test_class2.h"
#include <iostream>

using namespace std;

TestClass2::TestClass2()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void TestClass2::func()
{
    cout << __PRETTY_FUNCTION__ << endl;
}