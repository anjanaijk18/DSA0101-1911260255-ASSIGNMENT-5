First Program 

#include <iostream>
#include <stdexcept>
using namespace std;

void validate(double amount)
{
    if(amount < 0)
        throw invalid_argument("negative");

    if(amount > 1e6)
        throw out_of_range("too large");

    cout << "ok";
}

void process(double amount)
{
    try
    {
        validate(amount);
    }
    catch(const out_of_range& e)
    {
        cout << "log " << e.what() << " | ";
        throw;
    }
}

int main()
{
    for(double a : {100.0, -5.0, 2e6})
    {
        try
        {
            process(a);
            cout << "done";
        }
        catch(const exception& e)
        {
            cout << "caught " << e.what();
        }

        cout << '\n';
    }
    return 0;
}

Second Program 

#include <iostream>
#include <stdexcept>
using namespace std;

class ClaimError : public runtime_error
{
public:
    using runtime_error::runtime_error;
};

double approve(double billed, double cover)
{
    // TODO 1: Validate the bill and coverage
    if(billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if(billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover)
{
    try
    {
        return approve(billed, cover);
    }
    catch(const ClaimError& e)
    {
        // TODO 2: Audit and rethrow the same exception
        cout << "audit: " << e.what() << '\n';
        throw;
    }
}

int main()
{
    double claims[] = {40000, 50000, 60000, 20000, -1, 20000};
    double cover = 40000;

    for(double c : claims)
    {
        try
        {
            double paid = settle(c, cover);
            cout << "approved " << paid << '\n';
        }
        catch(const ClaimError& e)
        {
            cout << "claim rejected: " << e.what() << '\n';
        }
        catch(const exception& e)
        {
            cout << "error: " << e.what() << '\n';
        }
    }

    return 0;
}
