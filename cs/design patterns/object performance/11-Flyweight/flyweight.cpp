#include <iostream>
#include <string>
#include <map>
using namespace std;

class Font
{
    string key;

public:
    Font(const string &key)
        : key(key)
    {
    }
};

class FontFactory
{
    map<string, Font *> fontPool;

public:
    Font *getFont(const string &key)
    {
        map<string, Font *>::iterator it = fontPool.find(key);
        if (it == fontPool.end())
        {
            cout << "new font " << key << endl;
            Font *f = new Font(key);
            fontPool[key] = f;
        }
        return fontPool[key];
    }
};

int main()
{
    FontFactory ff;
    cout << ff.getFont("123") << endl;
    cout << ff.getFont("abc") << endl;
    cout << ff.getFont("123") << endl;
}