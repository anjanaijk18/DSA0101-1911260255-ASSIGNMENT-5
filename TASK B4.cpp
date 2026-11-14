#include <iostream>
using namespace std;

class Bill
{
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class EmergencyBill : public Bill
{
    double treatment, medicine;

public:
    EmergencyBill(double t, double m)
        : treatment(t), medicine(m) {}

    double total() const override
    {
        return treatment + medicine;
    }
};

class DayCareBill : public Bill
{
    double room, treatment;

public:
    DayCareBill(double r, double t)
        : room(r), treatment(t) {}

    double total() const override
    {
        return room + treatment;
    }
};

class Payer
{
public:
    virtual double amountCovered(double bill) const = 0;
    virtual ~Payer() {}
};

class CorporatePayer : public Payer
{
public:
    double amountCovered(double bill) const override
    {
        return bill * 0.20;
    }
};

class SeniorCitizenPayer : public Payer
{
public:
    double amountCovered(double bill) const override
    {
        return bill * 0.15;
    }
};

class GovernmentPayer : public Payer
{
public:
    double amountCovered(double bill) const override
    {
        return bill * 0.50;
    }
};

int main()
{
    Bill *b = new EmergencyBill(5000, 2000);

    Payer *p = new GovernmentPayer();

    double amount = b->total();

    cout << "Emergency Bill = " << amount << endl;
    cout << "Government Coverage = "
         << p->amountCovered(amount) << endl;

    cout << "Patient Payment = "
         << amount - p->amountCovered(amount) << endl;

    delete b;
    delete p;

    return 0;
}
