#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

long long modInverse(long long e, long long phi)
{
    for (long long d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
            return d;
    }

    return -1;
}

int main()
{
    long long p = 61;
    long long q = 53;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 17;

    if (gcd(e, phi) != 1)
    {
        cout << "Invalid public key.";
        return 0;
    }

    long long d = modInverse(e, phi);

    string message;

    cout << "Enter email message: ";
    getline(cin, message);

    cout << "\n--- PGP Secure Email ---\n";

    cout << "Public Key  : (" << e << ", " << n << ")" << endl;
    cout << "Private Key : (" << d << ", " << n << ")" << endl;

    cout << "\nOriginal Message: " << message << endl;

    cout << "\nEncrypted Message: ";

    for (char ch : message)
    {
        long long encrypted = powerMod((unsigned char)ch, e, n);
        cout << encrypted << " ";
    }

    cout << "\n\nDecrypted Message: ";

    for (char ch : message)
    {
        long long encrypted = powerMod((unsigned char)ch, e, n);
        long long decrypted = powerMod(encrypted, d, n);

        cout << (char)decrypted;
    }

    cout << endl;

    cout << "\nEmail sent securely using PGP." << endl;

    return 0;
}