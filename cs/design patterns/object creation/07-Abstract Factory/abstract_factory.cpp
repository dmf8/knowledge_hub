#include <iostream>
using namespace std;

class IDBConnection
{
public:
    int i;
    IDBConnection(int i)
        : i(i)
    {
    }
};
class IDBCommand
{
public:
    int i;
    IDBCommand(int i)
        : i(i)
    {
    }
};
class IDataReader
{
public:
    int i;
    IDataReader(int i)
        : i(i)
    {
    }
};

class IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
    virtual IDBCommand *CreateDBCommand() = 0;
    virtual IDataReader *CreateDataReader() = 0;
    virtual ~IDBFactory() {}
};

class DBFactory1 : public IDBFactory
{
public:
    virtual ~DBFactory1() {}
    virtual IDBConnection *CreateDBConnection() override
    {
        return new IDBConnection(1);
    }
    virtual IDBCommand *CreateDBCommand() override
    {
        return new IDBCommand(1);
    }
    virtual IDataReader *CreateDataReader() override
    {
        return new IDataReader(1);
    }
};

class DBFactory2 : public IDBFactory
{
public:
    virtual ~DBFactory2() {}
    virtual IDBConnection *CreateDBConnection() override
    {
        return new IDBConnection(2);
    }
    virtual IDBCommand *CreateDBCommand() override
    {
        return new IDBCommand(2);
    }
    virtual IDataReader *CreateDataReader() override
    {
        return new IDataReader(2);
    }
};

class EmployeeDAO
{
public:
    IDBFactory *dbFactory;
    void func()
    {
        IDBConnection *connection = dbFactory->CreateDBConnection();
        IDBCommand *command = dbFactory->CreateDBCommand();
        IDataReader *dataReader = dbFactory->CreateDataReader();
        cout << connection->i << " " << command->i << " " << dataReader->i << endl;
    }
};

int main()
{
    EmployeeDAO e;
    e.dbFactory = new DBFactory2();
    e.func();
    return 0;
}