#include <bits/stdc++.h>
using namespace std;

vector<int> v;

string encrypt(string text, int shift)
{
    string encrypted = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]) && text[i] != ' ')
            {
                encrypted += char(int(text[i] + shift - 65) % 26 + 65);
            }
            if (islower(text[i]) && text[i] != ' ')
            {
                encrypted += char(int(text[i] + shift - 97) % 26 + 97);
            }
        }
        else
        {
            encrypted += text[i];
        }
        if (text[i] == ' ')
        {
            v.push_back(i);
        }
    }
    return encrypted;
}

string decrypt(string encrypted, int shift, vector<int> &v)
{
    string decrypted = "";
    int k = 0;
    for (int i = 0; i < encrypted.size(); i++)
    {
        if (k < v.size() && decrypted.size() == v[k])
        {
            decrypted += ' ';
            k++;
        }
        if (isalpha(encrypted[i]))
        {
            if (isupper(encrypted[i]))
            {
                decrypted += char(int(encrypted[i] - shift - 65 + 26) % 26 + 65);
            }
            if (islower(encrypted[i]))
            {
                decrypted += char(int(encrypted[i] - shift - 97 + 26) % 26 + 97);
            }
        }
        else
        {
            decrypted += encrypted[i];
        }
    }
    return decrypted;
}

int main()
{
    string text;
    cout << "Enter the message to be encrypted: " << endl;
    getline(cin, text);

    int shift;
    cout << "Enter the shift value to encrypt the message:" << endl;
    cin >> shift;

    string encrypted = encrypt(text, shift);
    cout << "Plaintext before encryption is:" << text << endl;
    cout << "Shift value used to encrypt the message is:" << shift << endl;
    cout << "Encrypted message is:" << encrypted << endl;

    string decrypted = decrypt(encrypted, shift, v);
    cout << "The decrypted message is:" << decrypted << endl;

    return 0;
}