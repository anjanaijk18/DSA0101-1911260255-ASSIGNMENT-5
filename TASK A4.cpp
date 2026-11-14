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

class UnknownPackage : public BillingError
{
public:
    UnknownPackage() : BillingError("Unknown government package") {}
};

class MissingPatientRecord : public BillingError
{
public:
    MissingPatientRecord() : BillingError("Patient record not found") {}
};
