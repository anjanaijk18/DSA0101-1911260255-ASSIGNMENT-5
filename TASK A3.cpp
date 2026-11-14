#include <iostream>
#include <algorithm>
using namespace std;

struct Bill
{
    double amount;
};

class Payer
{
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer
{
public:
    double amountCovered(const Bill& b) const override
    {
        return b.amount;
    }
};

class Insurance : public Payer
{
    double limit, copay;

public:
    Insurance(double l, double c) : limit(l), copay(c) {}

    double amountCovered(const Bill& b) const override
    {
        double covered = min(b.amount, limit);
        return covered * (100 - copay) / 100;
    }
};

class GovernmentScheme : public Payer
{
    double packageRate;

public:
    GovernmentScheme(double rate) : packageRate(rate) {}

    double amountCovered(const Bill& b) const override
    {
        return min(b.amount, packageRate);
    }
};

// New payer added without changing existing classes
class CorporatePayer : public Payer
{
    double percentage;

public:
    CorporatePayer(double p) : percentage(p) {}

    double amountCovered(const Bill& b) const override
    {
        return b.amount * percentage / 100;
    }
};

int main()
{
    Bill b = {10000};

    SelfPay s;
    Insurance i(8000, 20);
    GovernmentScheme g(7000);
    CorporatePayer c(90);

    Payer* payers[] = {&s, &i, &g, &c};

    cout << "HOSPITAL BILL: Rs." << b.amount << endl;

    cout << "Self Pay: Rs."
         << payers[0]->amountCovered(b) << endl;

    cout << "Insurance: Rs."
         << payers[1]->amountCovered(b) << endl;

    cout << "Government: Rs."
         << payers[2]->amountCovered(b) << endl;

    cout << "Corporate: Rs."
         << payers[3]->amountCovered(b) << endl;

    return 0;
}
