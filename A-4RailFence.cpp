#include <bits/stdc++.h>
using namespace std;

string encrypt(string text)
{
    string str1 = "", str2 = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            continue;
        }
        else if (i % 2 == 0)
        {
            str1 += text[i];
        }
        else
        {
            str2 += text[i];
        }
    }
    return str1 + str2;
}

string decrypt(string encrypted, string original)
{
    string decrypted = "";
    vector<int> v;
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] == ' ')
        {
            v.push_back(i);
        }
    }

    int split = (original.size() + 1) / 2;
    string str1 = encrypted.substr(0, split);
    string str2 = encrypted.substr(split);

    int i = 0, j = 0;
    for (int k = 0; k < original.size(); k++)
    {
        if (!v.empty() && k == v.front())
        {
            decrypted += ' ';
            v.erase(v.begin());
        }
        else if (i < str1.size() && (k % 2 == 0))
        {
            decrypted += str1[i++];
        }
        else if (j < str2.size())
        {
            decrypted += str2[j++];
        }
    }
    return decrypted;
}

int main()
{
    string text;
    cout << "Enter the text to be encrypted:" << endl;
    getline(cin, text);

    cout << "Original text is:" << text << endl;

    string encrypted = encrypt(text);
    cout << "Encrypted text is:" << encrypted << endl;

    string decrypted = decrypt(encrypted, text);
    cout << "Decrypted text is:" << decrypted << endl;

    return 0;
}