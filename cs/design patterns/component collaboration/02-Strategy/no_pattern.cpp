#include <iostream>
using namespace std;

enum TaxBase
{
    CN,
    US,
    DE,
};

class SalesOrder
{
    TaxBase tax;

public:
    void setCountry(int tax)
    {
        this->tax = (TaxBase)tax;
    }

    double CalculateTax()
    {
        if (tax == CN)
        {
            cout << "cn tax" << endl;
            return 0;
        }
        else if (tax == US)
        {
            cout << "us tax" << endl;
            return 0;
        }
        else if (tax == DE)
        {
            cout << "de tax" << endl;
            return 0;
        }
        return 0;
    }
};

int main()
{
    SalesOrder so;
    so.setCountry(CN);
    so.CalculateTax();
}