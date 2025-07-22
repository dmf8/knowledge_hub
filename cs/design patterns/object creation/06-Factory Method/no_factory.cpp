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

class MainForm
{
public:
    string path;
    int number;

    void ButtonClick()
    {
        ISplitter *splitter = new TxtSplitter(path, number);
        splitter->split();
    }
};

int main()
{
    MainForm mf;
    mf.path = "file1";
    mf.number = 5;

    mf.ButtonClick();
    return 0;
}