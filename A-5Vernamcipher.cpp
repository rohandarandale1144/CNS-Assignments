#include <bits/stdc++.h>
using namespace std;

string generateRandomKey(int length)
{
    string key = "";
    for (int i = 0; i < length; i++)
    {
        key += (char)((rand() % 26) + 'A');
    }
    return key;
}
string encrypt(string message, string key, string &hex)
{
    string encrypted = "";
    stringstream hexStream;
    for (int i = 0; i < message.size(); i++)
    {
        char encryptedChar = (toupper(message[i]) ^ toupper(key[i]));
        encrypted += encryptedChar;
        hexStream << hex << setw(2) << setfill('0') << (int)encryptedChar;
    }
    hex = hexStream.str();
    return encrypted;
}

string decrypt(string encrypted, string key)
{
    string decrypted = "";
    for (int i = 0; i < encrypted.size(); i++)
    {
        char decryptedChar = (encrypted[i] ^ toupper(key[i]));
        decrypted += decryptedChar;
    }
    return decrypted;
}

int main()
{
    string text;
    cout << "Enter the text to be encrypted: " << endl;
    getline(cin, text);

    string key = generateRandomKey(text.size());

    string hex;
    string encrypted = encrypt(text, key, hex);
    cout << "Encrypted message in HEX is: " << hex << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted message in HEX is: " << decrypted << endl;

    return 0;
}