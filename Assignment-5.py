import hashlib

def sha1Hash(message):
    sha1=hashlib.sha1()
    sha1.update(message.encode())
    return sha1.digest()

def bytesToHex(byte_array):
    hexString=""
    for byte in byte_array:
        hexString+=f"{byte:02x}"
    return hexString

def main():
    message=input("Enter the message to be hashed:")
    hashValue=sha1Hash(message)

    print("\nOriginal message is:", message)
    print("\nSHA-1 Hash of the message is:", bytesToHex(hashValue))

    receivedMessage="Hello"
    print("\nReceived message is:", receivedMessage)

    receivedMessageHash=sha1Hash(receivedMessage)
    print("\nSHA-1 Hash of the received message is:", bytesToHex(receivedMessageHash))

    if hashValue==receivedMessageHash:
        print("\nHash values are matching, message is verified")
    else:
        print("\nHash values are not matching, message is not verified")

if __name__ == "__main__":
    main()