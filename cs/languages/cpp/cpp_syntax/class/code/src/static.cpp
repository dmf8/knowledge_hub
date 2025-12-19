#include <iostream>
using namespace std;
#include "static.h"

const int TestStatic::i1 = 1;
// const int TestStatic::i2 = 20;
int TestStatic::i3 = 3;
const double TestStatic::d1 = 2.2;

void TestStatic::func1()
{
    cout << "static function realized in .cpp" << endl;
}
