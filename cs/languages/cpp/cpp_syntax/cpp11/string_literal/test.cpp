#include <iostream>
using namespace std;

int main()
{
    string s1 = R"(\)";
    string s2 = R"(\n\n\n\n)";
    string s3 = R"-()""()-"; // use - as delimiter
    string s4 = R"a(
)\
a""
)a";
    string s5 = R"(x = ""\y"")";
    string s6 = R"&(cod: "(x,y)")&"; // use & as delimiter
    cout << s1 << endl;
    cout << "---" << endl;
    cout << s2 << endl;
    cout << "---" << endl;
    cout << s3 << endl;
    cout << "---" << endl;
    cout << s4 << endl;
    cout << "---" << endl;
    cout << s5 << endl;
    cout << s4 << endl;
    cout << "---" << endl;
    cout << s6 << endl;
    return 0;
}