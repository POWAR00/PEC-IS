#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, cipher = "";

    cout << "Enter Plain Text: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            cipher += char('Z' - (ch - 'A'));
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            cipher += char('z' - (ch - 'a'));
        }
        else
        {
            cipher += ch;   // Keep spaces and symbols unchanged
        }
    }

    cout << "Cipher Text: " << cipher << endl;

    return 0;
}