#include <iostream>
using namespace std;

class NetworkState
{
public:
    NetworkState *pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual ~NetworkState() {}
};

class OpenState;
class CloseState;
class ConnectState;

class OpenState : public NetworkState
{
    static NetworkState *instance;

public:
    static NetworkState *getInstance()
    {
        return instance;
    }
    virtual ~OpenState() {}
    virtual void Operation1() override;
    virtual void Operation2() override;
};

class CloseState : public NetworkState
{
    static NetworkState *instance;

public:
    static NetworkState *getInstance()
    {
        return instance;
    }
    virtual ~CloseState() {}
    virtual void Operation1() override;
    virtual void Operation2() override;
};

class ConnectState : public NetworkState
{
    static NetworkState *instance;

public:
    static NetworkState *getInstance()
    {
        return instance;
    }
    virtual ~ConnectState() {}
    virtual void Operation1() override;
    virtual void Operation2() override;
};

void OpenState::Operation1()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = CloseState::getInstance();
}
void OpenState::Operation2()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = ConnectState::getInstance();
}

void CloseState::Operation1()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = ConnectState::getInstance();
}
void CloseState::Operation2()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = OpenState::getInstance();
}

void ConnectState::Operation1()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = OpenState::getInstance();
}
void ConnectState::Operation2()
{
    cout << __PRETTY_FUNCTION__ << endl;
    pNext = CloseState::getInstance();
}

NetworkState *OpenState::instance = new OpenState;
NetworkState *CloseState::instance = new CloseState;
NetworkState *ConnectState::instance = new ConnectState;

class NetworkProcessor
{
    NetworkState *pState;

public:
    NetworkProcessor(NetworkState *pState)
        : pState(pState)
    {
    }

    void Operation1()
    {
        pState->Operation1();
        pState = pState->pNext;
    }
    void Operation2()
    {
        pState->Operation2();
        pState = pState->pNext;
    }
};

int main()
{
    NetworkProcessor np(OpenState::getInstance());

    np.Operation1();
    np.Operation1();
    np.Operation2();
    np.Operation2();

    return 0;
}