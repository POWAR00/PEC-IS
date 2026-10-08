// Implementation of PGP Operations Using GnuPG Command Line

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int choice;

    cout << "===== PGP Operations Using GnuPG =====" << endl;
    cout << "1. Generate Key Pair" << endl;
    cout << "2. List Keys" << endl;
    cout << "3. Encrypt File" << endl;
    cout << "4. Decrypt File" << endl;
    cout << "5. Sign File" << endl;
    cout << "6. Verify Signature" << endl;
    cout << "7. Exit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            system("gpg --full-generate-key");
            break;

        case 2:
            system("gpg --list-keys");
            break;

        case 3:
            system("gpg --encrypt --armor --recipient bhakti@example.com message.txt");
            cout << "File encrypted successfully." << endl;
            break;

        case 4:
            system("gpg --decrypt message.txt.asc");
            break;

        case 5:
            system("gpg --clearsign message.txt");
            cout << "Digital signature created." << endl;
            break;

        case 6:
            system("gpg --verify message.txt.asc");
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}