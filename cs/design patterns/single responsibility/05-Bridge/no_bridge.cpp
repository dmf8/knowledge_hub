#include <string>
#include <iostream>
using namespace std;

struct Image
{
};

class Messager
{
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~Messager() {}
};

class PCMessagerBase : public Messager
{
public:
    virtual void PlaySound() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void DrawShape() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void WriteText() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void Connect() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class MobileMessagerBase : public Messager
{
public:
    virtual void PlaySound() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void DrawShape() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void WriteText() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void Connect() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class PCMessagerLite : public PCMessagerBase
{
public:
    virtual void Login(string username, string password) override
    {
        PCMessagerBase::Connect();
    }
    virtual void SendMessage(string message) override
    {
        PCMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) override
    {
        PCMessagerBase::DrawShape();
    }
};

class PCMessagerPerfect : public PCMessagerBase
{
public:
    virtual void Login(string username, string password) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::Connect();
    }
    virtual void SendMessage(string message) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::DrawShape();
    }
};

class MobileMessagerLite : public MobileMessagerBase
{
public:
    virtual void Login(string username, string password) override
    {
        MobileMessagerBase::Connect();
    }
    virtual void SendMessage(string message) override
    {
        MobileMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) override
    {
        MobileMessagerBase::DrawShape();
    }
};

class MobileMessagerPerfect : public MobileMessagerBase
{
public:
    virtual void Login(string username, string password) override
    {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::Connect();
    }
    virtual void SendMessage(string message) override
    {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) override
    {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::DrawShape();
    }
};

int main()
{
    Messager *m1 = new PCMessagerLite;
    Messager *m2 = new MobileMessagerPerfect;

    m1->Login("", "");
    m1->SendMessage("");
    m1->SendPicture(Image());

    m2->Login("", "");
    m2->SendMessage("");
    m2->SendPicture(Image());

    return 0;
}