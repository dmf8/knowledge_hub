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
    // namespace
    cout << "--namespace--" << endl;
    func();          //::func
    using np1::func; //
    np11::func();    // np1::func
    func();          // np1::func
    ::func();        //::func
    np1::func2();

    // using
    cout << "--using--" << endl;
    lcn();

    return 0;
}