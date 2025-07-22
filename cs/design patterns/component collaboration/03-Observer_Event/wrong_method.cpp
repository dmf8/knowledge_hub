#include <string>
#include <thread>
#include <iostream>
using namespace std;

class ProgressBar
{
public:
    void showProgress(int step, int number)
    {
        cout << __PRETTY_FUNCTION__ << ": " << step << "/" << number << endl;
    }
};

class FileSplitter
{
    string path;
    int number;
    ProgressBar *progress_bar;

public:
    FileSplitter(const string &path, int number, ProgressBar *progress_bar)
        : path(path),
          number(number),
          progress_bar(progress_bar)
    {
    }

    void split()
    {
        cout << "split " << path << " into " << number << " parts" << endl;
        for (int i = 0; i < number; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(500));
            progress_bar->showProgress(i + 1, number);
        }
    }
};

class MainForm
{
public:
    string path;
    int number;
    ProgressBar pb;

    void ButtonClick()
    {
        FileSplitter splitter(path, number, &pb);
        splitter.split();
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