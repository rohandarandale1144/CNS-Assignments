import hashlib
import random
import math

def isPrime(num):
    if num<=1:
        return False
    for i in range(2, int(math.sqrt(num))+1):
        if num%i==0:
            return False
    return True

def gcd(a, b):
    while b:
        a, b=b, a%b
    return a

def modInverse(a, m):
    for i in range(1, m):
        if (a*i)%m==1:
            return i
    return None

def findCoprime(phi):
    while True:
        e=random.randint(2, phi-1)
        if gcd(e, phi)==1:
            return e

def generateKeyPairs():
    p=q=1

    while not isPrime(p):
        p=random.randint(100, 1000)
    
    while not isPrime(q):
        q=random.randint(100, 1000)
    
    print(f"First Prime Number is: {p}")
    print(f"Second Prime Number is: {q}")

    n=p*q
    phi=(p-1)*(q-1)
    e=findCoprime(phi)
    d=modInverse(e, phi)

    return ((e, n), (d, n))

def encrypt(message, publicKey):
    e, n=publicKey
    encrypted=[pow(ord(char), e, n) for char in message]
    return encrypted

def decrypt(encrypted, privateKey):
    d, n=privateKey
    decrypted=''.join([chr(pow(char, d, n)) for char in encrypted])
    return decrypted

def generateSignature(message, privateKey):
    hashedMessage=hashlib.sha256(message.encode()).hexdigest()
    signature=encrypt(hashedMessage, privateKey)
    return signature

def verifySignature(message, signature, publicKey):
    hashedMessage=hashlib.sha256(message.encode()).hexdigest()
    decrypted=decrypt(signature, publicKey)
    return decrypted==hashedMessage

print("Generating RSA Key Pairs...")
publicKey, privateKey=generateKeyPairs()
print("RSA Key Pairs are generated")

print("Generated Public Key pair is: (e, n)", publicKey)
print("Generated Private Key pair is: (d, n)", privateKey)

text=input("Enter the text to be hashed:")
encrypted=encrypt(text, publicKey)
signature=generateSignature(text, privateKey)

print(f"Generated encrypted message is: {encrypted}")
print(f"Generated signature is: {signature}")

receivedMessage=decrypt(encrypted, privateKey)
print(f"Decrypted message is: {receivedMessage}")

isSignatureValid=verifySignature(text, signature, publicKey)
if isSignatureValid:
    print("Signature is verified, message integrity is verified")
else:
    print("Message integrity is not verified")