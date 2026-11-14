#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class
class Bill
{
protected:
    int patientID;
    string patientName;

public:
    Bill(int id, string name)
        : patientID(id), patientName(name) {}

    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const
    {
        cout << "Patient ID: " << patientID
             << "\nPatient Name: " << patientName
             << "\nBill Type: " << type()
             << "\nTotal: Rs. " << total() << "\n\n";
    }

    virtual ~Bill() {}
};

// Outpatient Bill
class OutPatientBill : public Bill
{
    double consultation, tests;

public:
    OutPatientBill(int id, string name, double c, double t)
        : Bill(id, name), consultation(c), tests(t) {}

    double total() const override
    {
        return consultation + tests;
    }

    string type() const override
    {
        return "Outpatient";
    }
};

// Inpatient Bill
class InPatientBill : public Bill
{
    double roomCharge;
    int days;

public:
    InPatientBill(int id, string name, double r, int d)
        : Bill(id, name), roomCharge(r), days(d) {}

    double total() const override
    {
        return roomCharge * days;
    }

    string type() const override
    {
        return "Inpatient";
    }
};

// Procedure Bill
class ProcedureBill : public Bill
{
    double procedureFee, medicines;

public:
    ProcedureBill(int id, string name, double p, double m)
        : Bill(id, name), procedureFee(p), medicines(m) {}

    double total() const override
    {
        return procedureFee + medicines;
    }

    string type() const override
    {
        return "Procedure";
    }
};

// Daycare Bill
class DayCareBill : public Bill
{
    double packageAmount;

public:
    DayCareBill(int id, string name, double p)
        : Bill(id, name), packageAmount(p) {}

    double total() const override
    {
        return packageAmount;
    }

    string type() const override
    {
        return "Daycare";
    }
};

// Emergency Bill
class EmergencyBill : public Bill
{
    double baseCharge, extraCharge;

public:
    EmergencyBill(int id, string name, double b, double e)
        : Bill(id, name), baseCharge(b), extraCharge(e) {}

    double total() const override
    {
        return baseCharge + extraCharge;
    }

    string type() const override
    {
        return "Emergency";
    }
};

int main()
{
    vector<Bill*> bills;

    bills.push_back(new OutPatientBill(101, "Arun", 500, 300));
    bills.push_back(new InPatientBill(102, "Priya", 1000, 3));
    bills.push_back(new ProcedureBill(103, "Rahul", 5000, 1500));
    bills.push_back(new DayCareBill(104, "Meena", 2500));
    bills.push_back(new EmergencyBill(105, "Kiran", 2000, 1000));

    double grandTotal = 0;

    cout << "HOSPITAL BILLING SYSTEM\n\n";

    for(Bill* b : bills)
    {
        b->print();
        grandTotal += b->total();
    }

    cout << "GRAND TOTAL: Rs. " << grandTotal << endl;

    for(Bill* b : bills)
        delete b;

    return 0;
}
