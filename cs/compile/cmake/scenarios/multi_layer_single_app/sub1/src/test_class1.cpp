#include "test_class1.h"
#include <iostream>
#include "test_class2.h"

using namespace std;

TestClass1::TestClass1()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void TestClass1::func()
{
    TestClass2 tc2;
    tc2.func();
}