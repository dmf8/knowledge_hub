class Operator
{
    friend Operator operator+(const Operator &o, int n);
    friend Operator operator+(int n, const Operator &o);

public:
    Operator(int org = 0);
    Operator operator+(const Operator &o) const;
    Operator &operator++();
    Operator operator++(int);

    void show() const;
    int getValue() const;

private:
    int org = 2;
};

Operator operator+(const Operator &o, int n);
Operator operator+(int n, const Operator &o);