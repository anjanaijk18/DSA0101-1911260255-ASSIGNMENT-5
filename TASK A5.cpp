#include <iostream>
#include <string>
using namespace std;

struct Guard
{
string n;

explicit Guard(const string& s) : n(s) {}

~Guard()
{
    cout << '~' << n << '\n';
}
};

void f()
{
Guard g("f");
throw 42;
}

int main()
{
try
{
Guard m("main");
f();
cout << "not printed";
}
catch(int x)
{
cout << "caught " << x;
}
catch(...)
{
cout << "other";
}

cout << '\n';
}
