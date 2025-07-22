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

// decorator
class DecoratorStream : public Stream // keep same interface with stream
{
protected:
    Stream *stream; // file type polymorphic

public:
    DecoratorStream(Stream *stream)
        : stream(stream)
    {
    }
    virtual ~DecoratorStream() {}
};

// crypto
class CryptoStream : public DecoratorStream
{
public:
    CryptoStream(Stream *stream)
        : DecoratorStream(stream)
    {
    }
    virtual ~CryptoStream() {}

    virtual char Read(int number) override
    {
        cout << "crypto read" << endl;
        char ret = stream->Read(number);
        return ret;
    }
    virtual void Seek(int position) override
    {
        stream->Seek(position);
    }
    virtual void Write(char data) override
    {
        stream->Write(data);
    }
};

// buffer
class BufferedStream : public DecoratorStream
{
public:
    BufferedStream(Stream *stream)
        : DecoratorStream(stream)
    {
    }
    virtual ~BufferedStream() {}

    virtual char Read(int number) override
    {
        cout << "buffered read" << endl;
        char ret = stream->Read(number);
        return ret;
    }
    virtual void Seek(int position) override
    {
        stream->Seek(position);
    }
    virtual void Write(char data) override
    {
        stream->Write(data);
    }
};

void process()
{
    FileStream *fs = new FileStream;
    CryptoStream *cs = new CryptoStream(fs);
    BufferedStream *bs = new BufferedStream(fs);
    BufferedStream *bs2 = new BufferedStream(cs);

    cs->Read(0);
    bs->Read(0);
    bs2->Read(0);
}

int main()
{
    process();
}