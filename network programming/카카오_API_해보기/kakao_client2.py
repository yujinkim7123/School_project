import requests
from PIL import Image, ImageFilter

API_URL = 'https://kapi.kakao.com/v1/vision/face/detect'
MYAPP_KEY = '3ee5843bf6996ac9c5616cf6930192b3'


def detect_face(filename):
    headers = {'Authorization' : 'KakaoAK {}'.format(MYAPP_KEY)}
    files = {'file' : open(filename, 'rb')}
    rsp = requests.post(API_URL,  headers=headers, files=files)
    return rsp.json()

def mosaic(filename, detection_result):
    image = Image.open(filename)

    for face in detection_result['result']['faces']:          
        x = int(face['x']*image.width)
        y = int(face['y']*image.height)
        w = int(face['w']*image.width) 
        h = int(face['h']*image.height) 
        box = image.crop((x,y,x+w,y+h))
        box = box.resize((20,20), Image.NEAREST).resize((w,h), Image.NEAREST) 
        image.paste(box, (x,y,x+w,y+h))

    return image

if __name__=="__main__":
    
    IMAGE = 'profile.jpg' 
    detection_result = detect_face(IMAGE) 
    image = mosaic(IMAGE, detection_result) 
    image.show() 
