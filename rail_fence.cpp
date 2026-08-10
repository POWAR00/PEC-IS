#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    int key;

    cout << "Enter message: ";
    getline(cin, text);

    cout << "Enter number of rails: ";
    cin >> key;

    // Create rail matrix
    char rail[100][100];

    // Fill matrix with spaces
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            rail[i][j] = ' ';
        }
    }

    int row = 0;
    bool down = true;

    // Place characters in zigzag pattern
    for (int i = 0; i < text.length(); i++)
    {
        rail[row][i] = text[i];

        if (row == key - 1)
        {
            down = false;
        }
        else if (row == 0)
        {
            down = true;
        }

        if (down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // Read characters row by row
    string encrypted = "";

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            if (rail[i][j] != ' ')
            {
                encrypted += rail[i][j];
            }
        }
    }

    cout << "Encrypted Message: " << encrypted;

    return 0;
}