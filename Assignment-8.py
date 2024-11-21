from PIL import Image
import numpy as np

def xor_encrypt_decrypt(data, key):
    return bytearray([b^key for b in data])

img_path=input("Enter the path of the image to be encrypted:")
key=int(input("Enter the encryption key (from 0 to 255):"))

try:
    with Image.open(img_path) as img:
        img=img.convert("RGB")
        pixel_data=np.array(img)

except Exception as e:
    print(f"Cannot open the image {e}")
    exit()

flat_pixel_data=pixel_data.flatten()
encrypted_pixel_data=xor_encrypt_decrypt(flat_pixel_data, key)

encrypted_pixel_data=np.array(encrypted_pixel_data).reshape(pixel_data.shape)

encrypted_img=Image.fromarray(encrypted_pixel_data, "RGB")
decrypted_img_path="decrypted_image1.png"
encrypted_img.save(decrypted_img_path)

print(f"Image is processed (encrypted/decrypted) & is saved as:{decrypted_img_path}")

try:
    encrypted_img.show()
except Exception as e:
    print(f"Cannot open the image {e}")