#include <string>
#include <iostream>
#include <list>
using namespace std;

class Component
{
public:
    virtual void process() = 0;
    virtual ~Component() {}
};

class Composite : public Component
{
    string name = "";
    list<Component *> elements = {};

public:
    Composite(const string &s)
        : name(s) {}

    void add(Component *element)
    {
        elements.push_back(element);
    }

    void remove(Component *element)
    {
        elements.remove(element);
    }

    virtual void process() override
    {
        // process current
        cout << __PRETTY_FUNCTION__ << " " << name << endl;
        // process leaf
        for (auto &e : elements)
            e->process();
    }
};

int main()
{
    Composite root("root");
    Composite treeNode1("treeNode1");
    Composite treeNode2("treeNode2");
    Composite treeNode3("treeNode3");
    Composite treeNode4("treeNode4");
    Composite left1("left1");
    Composite left2("left2");

    root.add(&treeNode1);
    treeNode1.add(&treeNode2);
    treeNode2.add(&left1);

    root.add(&treeNode3);
    treeNode3.add(&treeNode4);
    treeNode4.add(&left2);

    root.process();
    return 0;
}