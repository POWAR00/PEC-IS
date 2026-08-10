#include <iostream>
#include <string>
using namespace std;

int main()
{
    string message;
    int columns;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter number of columns: ";
    cin >> columns;

    int length = message.length();

    // Calculate number of rows
    int rows = length / columns;

    if (length % columns != 0)
    {
        rows++;
    }

    char matrix[100][100];

    // Fill empty spaces with X
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 'X';
        }
    }

    // Write message row-wise
    int k = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (k < length)
            {
                matrix[i][j] = message[k];
                k++;
            }
        }
    }

    // Display message rectangle
    cout << "\nMessage Rectangle:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    // Read column-wise for encryption
    string encrypted = "";

    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            encrypted += matrix[i][j];
        }
    }

    cout << "\nEncrypted Message: " << encrypted;

    return 0;
}