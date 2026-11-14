Method 1: Virtual Functions

#include <iostream>
using namespace std;

class Bill
{
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill
{
    double consultation, tests;

public:
    OutPatient(double c, double t)
        : consultation(c), tests(t) {}

    double total() const override
    {
        return consultation + tests;
    }
};

class InPatient : public Bill
{
    int days;
    double rate, surgery;

public:
    InPatient(int d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override
    {
        return days * rate + surgery;
    }
};

int main()
{
    Bill *bills[2];

    bills[0] = new OutPatient(500, 200);
    bills[1] = new InPatient(3, 2500, 4000);

    double sum = 0;

    for(int i = 0; i < 2; i++)
    {
        cout << bills[i]->total() << endl;
        sum += bills[i]->total();
    }

    cout << "Total = " << sum << endl;

    for(int i = 0; i < 2; i++)
        delete bills[i];

    return 0;
}

Method 2: Switch Statement

#include <iostream>
using namespace std;

struct Bill
{
    int type;
    double consultation, tests;
    int days;
    double rate, surgery;
};

double total(Bill b)
{
    switch(b.type)
    {
        case 1:
            return b.consultation + b.tests;

        case 2:
            return b.days * b.rate + b.surgery;

        default:
            return 0;
    }
}

int main()
{
    Bill bills[2] = {
        {1, 500, 200, 0, 0, 0},
        {2, 0, 0, 3, 2500, 4000}
    };

    double sum = 0;

    for(int i = 0; i < 2; i++)
    {
        cout << total(bills[i]) << endl;
        sum += total(bills[i]);
    }

    cout << "Total = " << sum << endl;

    return 0;
}
