#include <iostream>
using namespace std;

class ITarget
{
public:
    virtual void process() = 0;
};

class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

class OldClass : public IAdaptee
{
public:
    virtual void foo(int data) override
    {
        cout << __PRETTY_FUNCTION__ << " " << data << endl;
    }
    virtual int bar() override
    {
        return 1;
    }
};

class Adapter : public ITarget
{
protected:
    IAdaptee *adaptee;

public:
    Adapter(IAdaptee *adaptee)
        : adaptee(adaptee)
    {
    }

    virtual void process() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        int data = adaptee->bar();
        adaptee->foo(data);
    }
};

int main()
{
    IAdaptee *adaptee = new OldClass;
    ITarget *target = new Adapter(adaptee);

    target->process();

    return 0;
}
