#include <iostream>
using namespace std;

int main()
{
    int a, b, m;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter modulus: ";
    cin >> m;

    cout << "\nModular Addition = " << (a + b) % m << endl;

    cout << "Modular Subtraction = " << ((a - b) % m + m) % m << endl;

    cout << "Modular Multiplication = " << (a * b) % m << endl;

    if (b != 0)
    {
        cout << "Remainder of a / b = " << a % b << endl;
    }
    else
    {
        cout << "Division by zero is not possible." << endl;
    }

    return 0;
}