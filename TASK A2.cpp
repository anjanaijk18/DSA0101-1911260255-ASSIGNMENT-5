Pseudocode

START

Create a base class Bill
    Declare virtual destructor
    Declare virtual function total()
    Declare function show()

Create derived class OPBill
    Override destructor
    Override total() to return 500

MAIN
    Create a base class pointer b
    Allocate an OPBill object to b

    Call b->show()
    Call b->total()

    Delete b
    Print newline

STOP

#include <iostream>
using namespace std;

struct Bill
{
    virtual ~Bill()
    {
        cout << "~Bill ";
    }

    virtual double total() const = 0;

    void show() const
    {
        cout << total() << '\n';
    }
};

struct OPBill : Bill
{
    ~OPBill() override
    {
        cout << "~OPBill ";
    }

    double total() const override
    {
        return 500;
    }
};

int main()
{
    Bill* b = new OPBill;

    b->show();

    delete b;

    cout << '\n';

    return 0;
}
