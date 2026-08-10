#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string key, text;
    char matrix[5][5];
    bool used[26] = {false};

    cout << "Enter key: ";
    getline(cin, key);

    // Create 5x5 matrix
    string letters = "";

    for (char ch : key)
    {
        ch = toupper(ch);

        if (ch == 'J')
            ch = 'I';

        if (isalpha(ch) && !used[ch - 'A'])
        {
            letters += ch;
            used[ch - 'A'] = true;
        }
    }

    // Add remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'J')
            continue;

        if (!used[ch - 'A'])
        {
            letters += ch;
            used[ch - 'A'] = true;
        }
    }

    // Fill matrix
    int k = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = letters[k++];
        }
    }

    // Display matrix
    cout << "\nPlayfair Matrix:\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nEnter message: ";
    getline(cin, text);

    // Remove spaces and convert to uppercase
    string message = "";

    for (char ch : text)
    {
        if (isalpha(ch))
        {
            ch = toupper(ch);

            if (ch == 'J')
                ch = 'I';

            message += ch;
        }
    }

    // Add X between same letters
    string prepared = "";

    for (int i = 0; i < message.length(); i++)
    {
        prepared += message[i];

        if (i + 1 < message.length() &&
            message[i] == message[i + 1])
        {
            prepared += 'X';
        }
    }

    // Add X if length is odd
    if (prepared.length() % 2 != 0)
    {
        prepared += 'X';
    }

    string encrypted = "";

    // Encrypt pairs
    for (int i = 0; i < prepared.length(); i += 2)
    {
        char a = prepared[i];
        char b = prepared[i + 1];

        int row1, col1, row2, col2;

        // Find positions
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                if (matrix[r][c] == a)
                {
                    row1 = r;
                    col1 = c;
                }

                if (matrix[r][c] == b)
                {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        // Same row
        if (row1 == row2)
        {
            encrypted += matrix[row1][(col1 + 1) % 5];
            encrypted += matrix[row2][(col2 + 1) % 5];
        }

        // Same column
        else if (col1 == col2)
        {
            encrypted += matrix[(row1 + 1) % 5][col1];
            encrypted += matrix[(row2 + 1) % 5][col2];
        }

        // Rectangle rule
        else
        {
            encrypted += matrix[row1][col2];
            encrypted += matrix[row2][col1];
        }
    }

    cout << "\nEncrypted Message: " << encrypted;

    return 0;
}