#include <iostream>
using namespace std;

class Library
{
protected:
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
    virtual bool Step2() = 0;
    virtual void Step4() = 0;

public:
    void Run()
    {
        Step1();
        if (Step2())
        {
            Step3();
        }

        for (int i = 0; i < 4; ++i)
        {
            Step4();
        }

        Step5();
    }
    virtual ~Library() {}
};

class Application : public Library
{
protected:
    virtual bool Step2() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return true;
    }
    virtual void Step4() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

public:
    virtual ~Application() {}
};

int main()
{
    Library *pLib = new Application;

    pLib->Run();

    return 0;
}