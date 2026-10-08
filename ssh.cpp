#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdint>
using namespace std;

uint32_t leftRotate(uint32_t x, uint32_t n)
{
    return (x << n) | (x >> (32 - n));
}

string SHA1(string input)
{
    uint64_t originalLength = input.length() * 8;

    input += char(0x80);

    while ((input.length() % 64) != 56)
        input += char(0x00);

    for (int i = 7; i >= 0; i--)
        input += char((originalLength >> (i * 8)) & 0xFF);

    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    for (size_t chunk = 0; chunk < input.length(); chunk += 64)
    {
        uint32_t w[80];

        for (int i = 0; i < 16; i++)
        {
            w[i] =
                ((uint32_t)(unsigned char)input[chunk + i * 4] << 24) |
                ((uint32_t)(unsigned char)input[chunk + i * 4 + 1] << 16) |
                ((uint32_t)(unsigned char)input[chunk + i * 4 + 2] << 8) |
                ((uint32_t)(unsigned char)input[chunk + i * 4 + 3]);
        }

        for (int i = 16; i < 80; i++)
            w[i] = leftRotate(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;

        for (int i = 0; i < 80; i++)
        {
            uint32_t f, k;

            if (i < 20)
            {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            }
            else if (i < 40)
            {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            }
            else if (i < 60)
            {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            }
            else
            {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = leftRotate(a, 5) + f + e + k + w[i];

            e = d;
            d = c;
            c = leftRotate(b, 30);
            b = a;
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    stringstream ss;

    ss << hex << setfill('0')
       << setw(8) << h0
       << setw(8) << h1
       << setw(8) << h2
       << setw(8) << h3
       << setw(8) << h4;

    return ss.str();
}

int main()
{
    string input;

    cout << "Enter message: ";
    getline(cin, input);

    cout << "SHA-1 Hash: " << SHA1(input) << endl;

    return 0;
}