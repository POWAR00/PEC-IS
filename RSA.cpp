#include <iostream>
using namespace std;

// Function to calculate GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function for modular exponentiation
long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main()
{
    int p, q, n, phi, e, d;
    int message, encrypted, decrypted;

    // Step 1: Enter two prime numbers
    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter prime number q: ";
    cin >> q;

    // Step 2: Calculate n
    n = p * q;

    // Step 3: Calculate Euler's Totient
    phi = (p - 1) * (q - 1);

    // Step 4: Choose e
    cout << "Enter value of e (1 < e < " << phi
         << " and gcd(e, phi) = 1): ";
    cin >> e;

    if (gcd(e, phi) != 1)
    {
        cout << "Invalid value of e!" << endl;
        return 0;
    }

    // Step 5: Calculate d
    d = 1;
    while ((d * e) % phi != 1)
    {
        d++;
    }

    // Step 6: Enter message
    cout << "Enter message (less than " << n << "): ";
    cin >> message;

    if (message >= n)
    {
        cout << "Message must be less than n!" << endl;
        return 0;
    }

    // Encryption: C = M^e mod n
    encrypted = powerMod(message, e, n);

    // Decryption: M = C^d mod n
    decrypted = powerMod(encrypted, d, n);

    // Display results
    cout << "\n--- RSA Algorithm ---" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = " << n << endl;
    cout << "phi = " << phi << endl;
    cout << "Public Key  = (" << e << ", " << n << ")" << endl;
    cout << "Private Key = (" << d << ", " << n << ")" << endl;
    cout << "Original Message = " << message << endl;
    cout << "Encrypted Message = " << encrypted << endl;
    cout << "Decrypted Message = " << decrypted << endl;

    return 0;
}