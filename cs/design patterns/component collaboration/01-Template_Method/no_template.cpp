#include <iostream>
using namespace std;

class Library
{
public:
    void Step1()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Step3()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Step5()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Application
{
public:
    bool Step2()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return true;
    }
    void Step4()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    Library lib;
    Application app;

    lib.Step1();
    if (app.Step2())
    {
        lib.Step3();
    }

    for (int i = 0; i < 4; ++i)
    {
        app.Step4();
    }

    lib.Step5();

    return 0;
}