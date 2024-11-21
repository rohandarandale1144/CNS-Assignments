import socket
import time

class Sender:
    def __init__(self, e, n):
        self.e=e
        self.n=n
    
    def encrypt(self, text):
        startTime=time.perf_counter()
        cipherText=pow(text, self.e, self.n)
        encryptionTime=time.perf_counter()-startTime
        return cipherText, encryptionTime

def main():
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect(('localhost', 65432))
            print("Sender: Waiting for Public Keys from Receiver...")
            data=s.recv(1024).decode()
            e, n=map(int, data.split(','))
            print("Sender: Public Keys are reveiced from Receiver.")

            while True:
                try:
                    text=int(input("Enter the plaintext to be encrypted:"))
                    if text<=0 or text>=n:
                        raise ValueError("Plaintext must be in the range of 2 to n.")
                    break
                except ValueError as ve:
                    print(f"Invalid Input {ve}, please try again.")
                
            sender=Sender(e, n)
            cipherText, encryptionTime=sender.encrypt(text)
            print(f"Sender: Cipher text is:{cipherText}")
            print(f"Encryption time is:{encryptionTime:.6f} seconds")
            s.sendall(str(cipherText).encode())
            print("Sender: Cipher text is sent to Receiver.")
    
    except socket.error as se:
        print(f"Socket Error has occurred {se}")
    
    except Exception as e:
        print(f"Exception has occurred {e}")

if __name__=="__main__":
    main()