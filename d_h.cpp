#include <iostream>
using namespace std;

// Function for modular exponentiation
long long powerMod(long long base, long long exponent, long long mod)
{
    long long result = 1;

    while (exponent > 0)
    {
        result = (result * base) % mod;
        exponent--;
    }

    return result;
}

int main()
{
    long long p, g;
    long long privateA, privateB;
    long long publicA, publicB;
    long long keyA, keyB;

    // Public values
    cout << "Enter prime number (p): ";
    cin >> p;

    cout << "Enter primitive root (g): ";
    cin >> g;

    // Private keys
    cout << "Enter private key of User A: ";
    cin >> privateA;

    cout << "Enter private key of User B: ";
    cin >> privateB;

    // Calculate public keys
    publicA = powerMod(g, privateA, p);
    publicB = powerMod(g, privateB, p);

    // Calculate shared secret keys
    keyA = powerMod(publicB, privateA, p);
    keyB = powerMod(publicA, privateB, p);

    // Display results
    cout << "\n--- Diffie-Hellman Key Exchange ---" << endl;

    cout << "Prime number (p) = " << p << endl;
    cout << "Primitive root (g) = " << g << endl;

    cout << "\nUser A Public Key = " << publicA << endl;
    cout << "User B Public Key = " << publicB << endl;

    cout << "\nShared Key calculated by User A = " << keyA << endl;
    cout << "Shared Key calculated by User B = " << keyB << endl;

    if (keyA == keyB)
        cout << "\nKey Exchange Successful!" << endl;
    else
        cout << "\nKey Exchange Failed!" << endl;

    return 0;
}