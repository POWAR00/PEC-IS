#include <iostream>
#include <string>
using namespace std;

string permutation(string bits, int table[], int size)
{
    string result = "";

    for (int i = 0; i < size; i++)
        result += bits[table[i] - 1];

    return result;
}

string XOR(string a, string b)
{
    string result = "";

    for (int i = 0; i < a.length(); i++)
        result += (a[i] == b[i]) ? '0' : '1';

    return result;
}

int IP[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};

int E[48] = {
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

int P[32] = {
    16,7,20,21,
    29,12,28,17,
    1,15,23,26,
    5,18,31,10,
    2,8,24,14,
    32,27,3,9,
    19,13,30,6,
    22,11,4,25
};

int S1[4][16] = {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

string sbox(string input)
{
    string output = "";

    for (int i = 0; i < 48; i += 6)
    {
        string block = input.substr(i, 6);

        int row = (block[0] - '0') * 2 + (block[5] - '0');

        int col = 0;
        for (int j = 1; j <= 4; j++)
            col = col * 2 + (block[j] - '0');

        int value = S1[row][col];

        string binary = "";
        for (int j = 3; j >= 0; j--)
            binary += ((value >> j) & 1) + '0';

        output += binary;
    }

    return output;
}

int main()
{
    string plaintext, key;

    cout << "Enter 64-bit plaintext: ";
    cin >> plaintext;

    cout << "Enter 48-bit round key: ";
    cin >> key;

    if (plaintext.length() != 64 || key.length() != 48)
    {
        cout << "Invalid input!";
        return 0;
    }

    // Initial Permutation
    string permuted = permutation(plaintext, IP, 64);

    // Divide into two halves
    string L0 = permuted.substr(0, 32);
    string R0 = permuted.substr(32, 32);

    // Expansion
    string expanded = permutation(R0, E, 48);

    // XOR with round key
    string x = XOR(expanded, key);

    // S-Box
    string s = sbox(x);

    // P-Box
    string f = permutation(s, P, 32);

    // Single DES round
    string L1 = R0;
    string R1 = XOR(L0, f);

    cout << "\nAfter Initial Permutation:";
    cout << "\nL0 = " << L0;
    cout << "\nR0 = " << R0;

    cout << "\n\nExpanded R0 = " << expanded;

    cout << "\n\nAfter XOR = " << x;

    cout << "\n\nAfter S-Box = " << s;

    cout << "\n\nAfter P-Box = " << f;

    cout << "\n\nAfter Single Round:";
    cout << "\nL1 = " << L1;
    cout << "\nR1 = " << R1;

    cout << "\n\nOutput = " << L1 + R1;

    return 0;
}