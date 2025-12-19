#include <iostream>

class TestStatic
{
public:
    static const int i1;
    static const int i2 = 2;
    static int i3;
    static const double d1;

    static void func1();
    static void func2()
    {
        std::cout << "static function realized in .h" << std::endl;
    }
};
