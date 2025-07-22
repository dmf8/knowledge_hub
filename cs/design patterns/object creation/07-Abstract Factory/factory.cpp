#include <iostream>
using namespace std;

class IDBConnection
{
};
class IDBCommand
{
};
class IDataReader
{
};

// omit concrete factory method
class IDBConnectionFactory
{
public:
    IDBConnection *Create()
    {
        return new IDBConnection();
    }
};
class IDBCommandFactory
{
public:
    IDBCommand *Create()
    {
        return new IDBCommand();
    }
};
class IDataReaderFactory
{
public:
    IDataReader *Create()
    {
        return new IDataReader();
    }
};

class EmployeeDAO
{
    // multi factories work together
    IDBConnectionFactory *dbConnectionFactory;
    IDBCommandFactory *dbCommandFactory;
    IDataReaderFactory *dataReaderFactory;

public:
    void func()
    {
        IDBConnection *connection = dbConnectionFactory->Create();
        IDBCommand *command = dbCommandFactory->Create();
        IDataReader *dataReader = dataReaderFactory->Create();
        cout << connection << " " << command << " " << dataReader << endl;
    }
};

int main()
{
    EmployeeDAO e;
    e.func();
    return 0;
}