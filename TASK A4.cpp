Pseudocode – Hospital Billing Exception Handling
START

DEFINE class BillingError
    INHERIT from RuntimeError
    CONSTRUCTOR(message)
        CALL parent constructor with message

DEFINE class InvalidCharge
    INHERIT from BillingError
    CONSTRUCTOR
        SET message = "Negative bill amount"

DEFINE class ClaimAboveCoverage
    INHERIT from BillingError
    CONSTRUCTOR
        SET message = "Claim exceeds coverage limit"


FUNCTION validateBill(amount)

    IF amount < 0 THEN
        THROW InvalidCharge
    ELSE
        DISPLAY "Bill amount is valid"
    END IF

END FUNCTION


FUNCTION validateClaim(claim, limit)

    IF claim > limit THEN
        THROW ClaimAboveCoverage
    ELSE
        DISPLAY "Insurance claim is valid"
    END IF

END FUNCTION


MAIN

    TRY
        CALL validateBill(-500)

    CATCH BillingError e
        DISPLAY "Billing Error: ", e.message
    END TRY


    TRY
        CALL validateClaim(15000, 10000)

    CATCH BillingError e
        DISPLAY "Billing Error: ", e.message
    END TRY

STOP

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
