#include <iostream>
using namespace std;

// base class
class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;
    virtual ~Stream() {}
};

// main business
class FileStream : public Stream
{
public:
    virtual char Read(int number) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 'f';
    }
    virtual void Seek(int position) override
    {
    }
    virtual void Write(char data) override
    {
    }
    virtual ~FileStream() {}
};

class NetworkStream : public Stream
{
public:
    virtual char Read(int number) override
    {
        return 'n';
    }
    virtual void Seek(int position) override
    {
    }
    virtual void Write(char data) override
    {
    }
    virtual ~NetworkStream() {}
};

class MemoryStream : public Stream
{
public:
    virtual char Read(int number) override
    {
        return 'm';
    }
    virtual void Seek(int position) override
    {
    }
    virtual void Write(char data) override
    {
    }
    virtual ~MemoryStream() {}
};

// crypto
// same crypto logic for read
// same crypto logic for write
// same crypto logic for locate
class CryptoFileStream : public FileStream
{
public:
    virtual char Read(int number) override
    {
        // chrypo1
        cout << __PRETTY_FUNCTION__ << endl;
        char ret = FileStream::Read(number);
        // chrypo2
        return ret;
    }
    virtual void Seek(int position) override
    {
        // chrypo1
        FileStream::Seek(position);
        // chrypo2
    }
    virtual void Write(char data) override
    {
        // chrypo1
        FileStream::Write(data);
        // chrypo2
    }
    virtual ~CryptoFileStream() {}
};

class CryptoNetworkStream : public NetworkStream
{
};
class CryptoMemoryStream : public MemoryStream
{
};

// buffer
class BufferedFileStream : public FileStream
{
    virtual char Read(int position) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        char ret = FileStream::Read(position);
        return ret;
    }
};
class BufferedNetworkStream : public NetworkStream
{
};
class BufferedMemoryStream : public MemoryStream
{
};

// buffer+crypto
class CryptoBufferedFileStream : public FileStream
{
    virtual char Read(int position) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        char ret = FileStream::Read(position);
        return ret;
    }
};
class CryptoBufferedNetworkStream : public NetworkStream
{
};
class CryptoBufferedMemoryStream : public MemoryStream
{
};

void process()
{
    CryptoFileStream *fs1 = new CryptoFileStream;
    BufferedFileStream *fs2 = new BufferedFileStream;
    CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream;

    fs1->Read(0);
}

int main()
{
    process();
}