import socket
import time
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

def extended_gcd(a, b):
    if a==0:
        return b, 0, 1
    gcd, x1, y1=extended_gcd(b%a, a)
    x=y1-(b//a)*x1
    y=x1
    return gcd, x, y

def modInverse(e, phi):
    gcd, x, _=extended_gcd(e, phi)
    if gcd!=1:
        raise ValueError("Inverse doesn't exist")
    return x%phi

def findCoprime(phi):
    while True:
        e=random.randint(2, phi-1)
        if gcd(e, phi)==1:
            return e

class Receiver:
    def __init__(self, d, n):
        self.d=d
        self.n=n
    
    def decrypt(self, text):
        startTime=time.perf_counter()
        decryptedText=pow(text, self.d, self.n)
        decryptionTime=time.perf_counter()-startTime
        return decryptedText, decryptionTime

def main():
    p=int(input("Enter the first prime number: "))
    q=int(input("Enter the second prime number: "))

    if not isPrime(p) and isPrime(q):
        print("Both p and q must be prime")
        return
    
    print(f"First prime number is: {p}")
    print(f"Second prime number is: {q}")

    n=p*q
    phi=(p-1)*(q-1)
    e=findCoprime(phi)
    d=modInverse(e, phi)

    print(f"Generated Public Keys are: (e={e}, n={n})")
    print(f"Generated Private Keys are: (d={d}, n={n})")

    receiver=Receiver(d, n)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('localhost', 65432))
        s.listen()
        print(f"Receiver: Waiting for connection from Sender...")
        conn, addr=s.accept()

        with conn:
            print(f"Receiver: Connected to the Sender via address: {addr}")
            publicKeys=f"{e},{n}"
            conn.sendall(publicKeys.encode())
            print(f"Receiver: Public Keys are sent to the Sender.")

            data=conn.recv(1024)
            if data:
                cipherText=int(data.decode())
                print(f"Receiver: Received Cipher text is:{cipherText}")
                decryptedText, deryptionTime=receiver.decrypt(cipherText)
                print(f"Receiver: Decrypted text is:{decryptedText}")
                print(f"Receiver: Decryption Time is:{deryptionTime:.6f}")

if __name__ == "__main__":
    main()