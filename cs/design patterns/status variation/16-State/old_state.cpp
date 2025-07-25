#include <iostream>
using namespace std;

enum NetworkState
{
    Network_Open,
    Network_Close,
    Network_Connect,
};

class NetworkProcessor
{
    NetworkState state = Network_Open;

public:
    void Operation1()
    {
        cout << __PRETTY_FUNCTION__ << " " << state << endl;
        if (state == Network_Open)
        {
            state = Network_Close;
        }
        else if (state == Network_Close)
        {
            state = Network_Connect;
        }
        else if (state == Network_Connect)
        {
            state = Network_Open;
        }
    }
    void Operation2()
    {
        cout << __PRETTY_FUNCTION__ << " " << state << endl;
        if (state == Network_Open)
        {
            state = Network_Connect;
        }
        else if (state == Network_Close)
        {
            state = Network_Open;
        }
        else if (state == Network_Connect)
        {
            state = Network_Close;
        }
    }
};

int main()
{
    NetworkProcessor np;
    np.Operation1();
    np.Operation1();
    np.Operation2();
    np.Operation2();

    return 0;
}