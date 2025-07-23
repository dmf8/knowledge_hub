#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &s) {}

public:
    static Singleton *getInstance()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (!instance)
            instance = new Singleton;
        return instance;
    }
    static Singleton *getInstanceLock()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        lock_guard<mutex> lock(mtx);
        if (!instance)
            instance = new Singleton;
        return instance;
    }
    static Singleton *getInstanceBiCheck()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (!instance)
        {
            lock_guard<mutex> lock(mtx);
            if (!instance)
                instance = new Singleton;
        }
        return instance;
    }
    // static Singleton *getInstanceBiCheckNoReorder()
    // {
    //     cout << __PRETTY_FUNCTION__ << endl;
    //     if (!instance)
    //     {
    //         lock_guard<mutex> lock(mtx);
    //         if (!instance)
    //             instance = new Singleton;
    //     }
    //     return instance;
    // }

    static Singleton *instance;
    void test()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    // Singleton *s = Singleton::getInstance();
    // Singleton *s = Singleton::getInstanceLock();
    Singleton *s = Singleton::getInstanceBiCheck();
    cout << s << endl;
    s->test();
    return 0;
}