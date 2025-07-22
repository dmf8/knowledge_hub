#include <iostream>
using namespace std;

class ISplitter
{
protected:
    string path;
    int number;

public:
    ISplitter(const string &path, int number)
        : path(path),
          number(number)
    {
    }
    virtual ~ISplitter() {}
    virtual void split() = 0;
};

class TxtSplitter : public ISplitter
{
public:
    TxtSplitter(const string &path, int number)
        : ISplitter(path, number)
    {
    }
    virtual ~TxtSplitter() {}

    virtual void split() override
    {
        cout << __PRETTY_FUNCTION__
             << " split " << path << " into " << number << " parts" << endl;
    }
};

class PictureSplitter : public ISplitter
{
public:
    PictureSplitter(const string &path, int number)
        : ISplitter(path, number)
    {
    }
    virtual ~PictureSplitter() {}

    virtual void split() override
    {
        cout << __PRETTY_FUNCTION__
             << " split " << path << " into " << number << " parts" << endl;
    }
};

class SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter(const string &path, int number) = 0;
    virtual ~SplitterFactory() {}
};

class TxtSplitterFactory : public SplitterFactory
{
    virtual ISplitter *CreateSplitter(const string &path, int number) override
    {
        return new TxtSplitter(path, number);
    }
    virtual ~TxtSplitterFactory() {}
};

class PictureSplitterFactory : public SplitterFactory
{
    virtual ISplitter *CreateSplitter(const string &path, int number) override
    {
        return new PictureSplitter(path, number);
    }
    virtual ~PictureSplitterFactory() {}
};

class MainForm // use factory method
{
public:
    string path;
    int number;
    SplitterFactory *factory; // concrete type is determined by caller

    void ButtonClick()
    {
        ISplitter *splitter = factory->CreateSplitter(path, number);
        splitter->split();
    }
};

int main()
{
    MainForm mf;
    mf.path = "file1";
    mf.number = 5;
    mf.factory = new TxtSplitterFactory;

    mf.ButtonClick();
    return 0;
}