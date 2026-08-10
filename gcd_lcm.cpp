#include <iostream>
using namespace std;

int main()
{
    int a, b, x, y, remainder, gcd, lcm;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    x = a;
    y = b;

    // GCD using Euclidean Algorithm
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    gcd = a;

    // LCM formula
    lcm = (x * y) / gcd;

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm << endl;

    return 0;
}
