#include <iostream>
#include <stdexcept>
using namespace std;

class BillingError : public runtime_error
{
public:
    BillingError(string msg) : runtime_error(msg) {}
};

class InvalidCharge : public BillingError
{
public:
    InvalidCharge() : BillingError("Negative bill amount") {}
};

class ClaimAboveCoverage : public BillingError
{
public:
    ClaimAboveCoverage() : BillingError("Claim exceeds coverage limit") {}
};

void validateBill(double amount)
{
    if(amount < 0)
        throw InvalidCharge();

    cout << "Bill amount is valid" << endl;
}

void validateClaim(double claim, double limit)
{
    if(claim > limit)
        throw ClaimAboveCoverage();

    cout << "Insurance claim is valid" << endl;
}

int main()
{
    try
    {
        validateBill(-500);
    }
    catch(const BillingError& e)
    {
        cout << "Billing Error: " << e.what() << endl;
    }

    try
    {
        validateClaim(15000, 10000);
    }
    catch(const BillingError& e)
    {
        cout << "Billing Error: " << e.what() << endl;
    }

    return 0;
}
