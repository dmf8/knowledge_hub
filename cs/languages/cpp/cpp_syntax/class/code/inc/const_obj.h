class ConstObj
{
public:
    void funcConst() const;
    void func();

private:
    int a = 0;
    mutable int b = 10;
};