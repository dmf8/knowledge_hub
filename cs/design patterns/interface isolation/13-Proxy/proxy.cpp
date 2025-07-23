#include <iostream>
using namespace std;

class ISubject
{
public:
    virtual void process() = 0;
};

class RealSubject : public ISubject
{
public:
    virtual void process() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class SubjectProxy : public ISubject
{
    RealSubject *subject;

public:
    SubjectProxy()
    {
        subject = new RealSubject;
    }
    virtual void process() override
    {
        cout << "some trivial affairs" << endl;
        subject->process();
    }
};

int main()
{
    // no proxy
    // ISubject *subject = new RealSubject;
    // subject->process();

    // proxy
    ISubject *subject = new SubjectProxy;
    subject->process();

    return 0;
}