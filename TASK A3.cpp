PSEUDO CODE : 

START

DEFINE structure Bill
    DECLARE amount

DEFINE abstract class Payer
    DECLARE virtual function amountCovered(Bill)

DEFINE class SelfPay INHERITS Payer
    FUNCTION amountCovered(Bill)
        RETURN Bill.amount

DEFINE class Insurance INHERITS Payer
    DECLARE limit, copay

    CONSTRUCTOR(limit, copay)
        STORE limit and copay

    FUNCTION amountCovered(Bill)
        covered = MIN(Bill.amount, limit)
        RETURN covered * (100 - copay) / 100

DEFINE class GovernmentScheme INHERITS Payer
    DECLARE packageRate

    CONSTRUCTOR(rate)
        STORE packageRate

    FUNCTION amountCovered(Bill)
        RETURN MIN(Bill.amount, packageRate)

DEFINE class CorporatePayer INHERITS Payer
    DECLARE percentage

    CONSTRUCTOR(percentage)
        STORE percentage

    FUNCTION amountCovered(Bill)
        RETURN Bill.amount * percentage / 100

MAIN

    CREATE Bill b
    SET b.amount = 10000

    CREATE SelfPay object s
    CREATE Insurance object i WITH (8000, 20)
    CREATE GovernmentScheme object g WITH (7000)
    CREATE CorporatePayer object c WITH (90)

    CREATE array of Payer pointers
        payers = {s, i, g, c}

    DISPLAY "HOSPITAL BILL: Rs.", b.amount

    DISPLAY "Self Pay: Rs.", payers[0].amountCovered(b)

    DISPLAY "Insurance: Rs.", payers[1].amountCovered(b)

    DISPLAY "Government: Rs.", payers[2].amountCovered(b)

    DISPLAY "Corporate: Rs.", payers[3].amountCovered(b)

STOP
    
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
