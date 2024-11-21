#include <bits/stdc++.h>
using namespace std;

string generateKey(string text, string key)
{
    int messLen = text.size();
    int keyLen = key.size();
    string newKey = key;

    while (newKey.size() < messLen)
    {
        newKey += key;
    }
    newKey = newKey.substr(0, messLen);
    return newKey;
}

string encrypt(string text, string key)
{
    string encrypted = "";
    for (int i = 0; i < text.size(); i++)
    {
        char encryptedChar = ((toupper(text[i] - 'A') + toupper(key[i] - 'A') % 26));
        encryptedChar += 'A';
        encrypted += encryptedChar;
    }
    return encrypted;
}

string decrypt(string encrypted, string key)
{
    string decrypted = "";
    for (int i = 0; i < encrypted.size(); i++)
    {
        char decryptedChar = ((toupper(encrypted[i] - 'A') - (toupper(key[i] - 'A') + 26) % 26));
        decryptedChar += 'A';
        decrypted += decryptedChar;
    }
    return decrypted;
}
int main()
{
    string text;
    cout << "Enter the text to be encrypted:" << endl;
    getline(cin, text);

    string key;
    cout << "Enter the key for the message:" << endl;
    cin >> key;

    string newKey = generateKey(text, key);
    cout << "New Key generated is:" << newKey << endl;

    string encrypted = encrypt(text, newKey);
    cout << "Encrypted Message is:" << encrypted << endl;

    string decrypted = decrypt(encrypted, newKey);
    cout << "Decrypted Message is:" << decrypted << endl;

    return 0;
}