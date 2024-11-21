#include <bits/stdc++.h>
using namespace std;

string encrypt(string text)
{
    map<char, char> mp = {
        {'a', 'd'}, {'b', 'e'}, {'c', 'f'}, {'d', 'g'}, {'e', 'h'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'}, {'k', 'n'}, {'l', 'o'}, {'m', 'p'}, {'n', 'q'}, {'o', 'r'}, {'p', 's'}, {'q', 't'}, {'r', 'u'}, {'s', 'v'}, {'t', 'w'}, {'u', 'x'}, {'v', 'y'}, {'w', 'z'}, {'x', 'a'}, {'y', 'b'}, {'z', 'c'}};
    string encrypted = "";
    for (char &ch : text)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                encrypted += toupper(mp[tolower(ch)]);
            }
            if (islower(ch))
            {
                encrypted += tolower(mp[ch]);
            }
        }
        else
        {
            encrypted += ch;
        }
    }
    return encrypted;
}

string decrypt(string encrypted)
{
    map<char, char> mp = {
        {'d', 'a'}, {'e', 'b'}, {'f', 'c'}, {'g', 'd'}, {'h', 'e'}, {'i', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'o', 'l'}, {'p', 'm'}, {'q', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'}, {'u', 'r'}, {'v', 's'}, {'w', 't'}, {'x', 'u'}, {'y', 'v'}, {'z', 'w'}, {'a', 'x'}, {'b', 'y'}, {'c', 'z'}};
    string decrypted = "";
    for (char &ch : encrypted)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                decrypted += toupper(mp[tolower(ch)]);
            }
            if (islower(ch))
            {
                decrypted += tolower(mp[ch]);
            }
        }
        else
        {
            decrypted += ch;
        }
    }
    return decrypted;
}
int main()
{
    string text;
    cout << "Enter teh text to be encrypted:" << endl;
    getline(cin, text);

    cout << "Original text is:" << text << endl;

    string encrypted = encrypt(text);
    cout << "Encrypted text is:" << encrypted << endl;

    string decrypted = decrypt(encrypted);
    cout << "Decrypted text is:" << decrypted << endl;

    return 0;
}