#include <iostream>
#include <atomic>
using namespace std;

int main()
{
    // construction
    atomic<bool> a1{false};
    cout << "a1: " << a1.load() << endl;

    // initialize
    atomic<int> a2;
    cout << "uninit a2: " << a2.load() << endl;
    atomic_init(&a2, 5);
    cout << "init a2: " << a2.load() << endl;

    return 0;
}