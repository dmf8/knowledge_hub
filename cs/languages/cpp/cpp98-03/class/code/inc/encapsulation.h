class Encapsulation
{
public:
    Encapsulation();

    void defaultParams(int p1, int p2);
    void defaultParams2(int p = i);
    void formalParams(int, double);
    void formalParams2(int, double d);

    void func();
    void func() const;

private:
    static int i;
};