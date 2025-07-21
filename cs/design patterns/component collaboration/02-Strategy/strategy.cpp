#include <iostream>
using namespace std;

struct Context
{
};

class TaxStrategy
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStrategy() {}
};

class CNTax : public TaxStrategy
{
    virtual double Calculate(const Context &context) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

class USTax : public TaxStrategy
{
    virtual double Calculate(const Context &context) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

class DETax : public TaxStrategy
{
    virtual double Calculate(const Context &context) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

class SalesOrder
{
    TaxStrategy *strategy;

public:
    SalesOrder(TaxStrategy *strategy)
        : strategy(strategy)
    {
    }

    ~SalesOrder()
    {
        delete this->strategy;
    }

    double CalculateTax()
    {
        Context context;
        double val = strategy->Calculate(context);
        return val;
    }
};

int main()
{
    SalesOrder so(new USTax);
    so.CalculateTax();
}