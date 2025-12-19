#include <iostream>
using namespace std;

int a = 0;

void test()
{
    int a = 1;
    cout << a << endl;
    cout << ::a << endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
