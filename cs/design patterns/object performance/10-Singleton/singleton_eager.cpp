#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &s) {}

public:
    static Singleton *getInstance()
    {
        return instance;
    }
    static Singleton *instance;
    void test()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

Singleton *Singleton::instance = new Singleton;

int main()
{
    Singleton *s = Singleton::getInstance();
    cout << s << endl;
    s->test();
    return 0;
}