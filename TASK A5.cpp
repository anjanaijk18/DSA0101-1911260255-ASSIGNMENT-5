Pseudocode – Exception Handling and Stack Unwinding in C++

START

DEFINE structure Guard
    DECLARE string n

    CONSTRUCTOR Guard(s)
        SET n = s

    DESTRUCTOR
        DISPLAY "~", n

DEFINE FUNCTION f()

    CREATE Guard object g WITH name "f"

    THROW integer value 42

END FUNCTION


MAIN

    TRY
        CREATE Guard object m WITH name "main"

        CALL function f()

        DISPLAY "not printed"

    CATCH integer x
        DISPLAY "caught ", x

    CATCH any other exception
        DISPLAY "other"

    END TRY

    DISPLAY newline

STOP

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
