#include <string>
#include <list>
#include <thread>
#include <iostream>
using namespace std;

class IProgress
{
public:
    virtual ~IProgress() {}
    virtual void showProgress(float progress) = 0;
};

class FileSplitter
{
    string path;
    int number;
    list<IProgress *> progress;

public:
    FileSplitter(const string &path, int number)
        : path(path),
          number(number)
    {
    }
    virtual ~FileSplitter() {}

    void addProgress(IProgress *p)
    {
        progress.push_back(p);
    }

    void removeProgress(IProgress *p)
    {
        progress.remove(p);
    }

    void split()
    {
        cout << "split " << path << " into " << number << " parts" << endl;
        for (int i = 0; i < number; ++i)
        {
            // do split
            this_thread::sleep_for(chrono::milliseconds(500));
            float progress_value = (float)(i + 1) / number;

            // inform
            onProgress(progress_value);
        }
    }

protected:
    virtual void onProgress(float value)
    {
        for (IProgress *p : progress)
            p->showProgress(value);
    }
};

class MainForm : public IProgress
{
public:
    string path;
    int number;

    void ButtonClick()
    {
        FileSplitter splitter(path, number);
        splitter.addProgress(this);
        splitter.split();
    }

    virtual void showProgress(float progress) override
    {
        cout << __PRETTY_FUNCTION__ << " progress bar " << progress << endl;
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