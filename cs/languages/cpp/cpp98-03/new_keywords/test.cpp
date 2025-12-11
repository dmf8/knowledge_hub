#include <iostream>
using namespace std;

void func()
{
    cout << "::func" << endl;
}

namespace np1
{
    void func()
    {
        cout << "np1::func" << endl;
    }
} // namespace np1

namespace np2
{
    void func()
    {
        cout << "np2::func" << endl;
    }
}

namespace np11 = np1;

namespace np1
{
    void func2()
    {
        cout << "np1::func2" << endl;
    }
}

class LongClassName
{
public:
    LongClassName()
    {
        cout << __FUNCTION__ << endl;
    }
};

using lcn = LongClassName;

int main()
{
    func();
    using np1::func;
    np11::func();
    func();
    ::func();
    np1::func2();

    lcn();

    return 0;
}