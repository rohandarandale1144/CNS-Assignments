#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

long long modInverse(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{

    long long prime, generator;
    do
    {
        cout << "Enter the prime number:" << endl;
        cin >> prime;
        if (!isPrime(prime))
        {
            cout << "Entered number is not prime, please try again." << endl;
        }
    } while (!isPrime(prime));

    cout << "Enter the value of the generator:" << endl;
    cin >> generator;

    long long rohanPrivateKey, rajPrivateKey, prathamPrivateKey;
    cout << "Enter the private key for rohan:" << endl;
    cin >> rohanPrivateKey;
    cout << "Enter the private key for raj:" << endl;
    cin >> rajPrivateKey;
    cout << "Enter the private key for pratham:" << endl;
    cin >> prathamPrivateKey;

    long long rohanPublicKey = modInverse(generator, rohanPrivateKey, prime);
    long long rajPublicKey = modInverse(generator, rajPrivateKey, prime);
    long long prathamPublicKeyForRohan = modInverse(generator, prathamPrivateKey, prime);
    long long prathamPublicKeyForRaj = modInverse(generator, prathamPrivateKey, prime);

    int ch;
    cout << "Enter your choice:" << endl;
    cout << "1: Secure Key exchange between Rohan & Raj:" << endl;
    cout << "2: MITM Attack by Pratham:" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "Rohan's Public Key is:" << rohanPublicKey << endl;
        cout << "Raj's Public Key is:" << rajPublicKey << endl;

        long long sharedSecretbyRohan = modInverse(rajPublicKey, rohanPrivateKey, prime);
        long long sharedSecretbyRaj = modInverse(rohanPublicKey, rajPrivateKey, prime);

        cout << "Shared Secret by Rohan with Raj:" << sharedSecretbyRohan << endl;
        cout << "Shared Secret by Raj with Rohan:" << sharedSecretbyRaj << endl;

        if (sharedSecretbyRohan == sharedSecretbyRaj)
        {
            cout << "Shared secret key is matched, secure communication is established." << endl;
        }
        else
        {
            cout << "Shared secret key is not matched, secure communication is not established." << endl;
        }
    }
    else if (ch == 2)
    {
        cout << "Rohan's Public Key is:" << rohanPublicKey << endl;
        cout << "Raj's Public Key is:" << rajPublicKey << endl;

        long long sharedSecretByRohanWithPratham = modInverse(prathamPublicKeyForRohan, rohanPrivateKey, prime);
        long long sharedSecretByRajWithPratham = modInverse(prathamPublicKeyForRaj, rajPrivateKey, prime);

        cout << "Shared Secret by Rohan to Pratham (Thinking its Raj) is: " << sharedSecretByRohanWithPratham << endl;
        cout << "Shared Secret by Raj with Pratham (Thinking its Rohan) is:" << sharedSecretByRajWithPratham << endl;

        long long sharedSecretPrathamWithRohan = modInverse(rohanPublicKey, prathamPrivateKey, prime);
        long long sharedSecretPrathamWithRaj = modInverse(rajPublicKey, prathamPrivateKey, prime);

        cout << "Shared Secret by Pratham to Rohan (By the name of Raj) is:" << sharedSecretPrathamWithRohan << endl;
        cout << "Shared Secret by Pratham to Raj (By the name of Rohan) is:" << sharedSecretPrathamWithRaj << endl;

        if (sharedSecretByRohanWithPratham == sharedSecretPrathamWithRohan && sharedSecretByRajWithPratham == sharedSecretPrathamWithRaj)
        {
            cout << "MITM Attack is successful, message is tampered with." << endl;
        }
        else
        {
            cout << "MITM Attack is unsuccessful, message is not tampered with." << endl;
        }
    }
    else
    {
        cout << "Invalid Choice, Please select the correct option." << endl;
    }
    return 0;
}