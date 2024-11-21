#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int key)
{
    for (char &ch : text)
    {
        ch = (ch + 3) ^ key;
    }
    return text;
}

string decrypt(string encrypted, int key)
{
    for (char &ch : encrypted)
    {
        ch = (ch ^ key) - 3;
    }
    return encrypted;
}
int main()
{

    string text;
    cout << "Enter the text to be encrypted:" << endl;
    getline(cin, text);

    int key;
    cout << "Enter the key to encrypt the text:" << endl;
    cin >> key;

    string encrypted = encrypt(text, key);
    cout << "Encrypted text is:" << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted text is:" << decrypted << endl
         << endl;

    return 0;
}