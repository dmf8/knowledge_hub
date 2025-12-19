#include <iostream>
using namespace std;
#include "explicit.h"

TestExplicit::TestExplicit(int i)
    : i(i)
{
    cout << __FUNCTION__ << " " << i << endl;
}