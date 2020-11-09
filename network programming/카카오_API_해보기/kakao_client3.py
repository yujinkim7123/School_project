import requests
from PIL import Image, ImageDraw
from io import BytesIO


API_URL = 'https://kapi.kakao.com/v1/vision/product/detect'
MYAPP_KEY = '3ee5843bf6996ac9c5616cf6930192b3'

def detect_product(image_url):
    
    headers = {'Authorization': 'KakaoAK {}'.format(MYAPP_KEY)}
    data = { 'image_url' : image_url}
    resp = requests.post(API_URL, headers=headers, data=data) 
    return resp.json()

def show_products(image_url, detection_result):
    image_rsp = requests.get(image_url)
    file_jpgdata = BytesIO(image_rsp.content)
    image = Image.open(file_jpgdata)


    draw = ImageDraw.Draw(image)

    for obj in detection_result['result']['objects']:
        x1 = int(obj['x1']*image.width) 
        y1 = int(obj['y1']*image.height)
        x2 = int(obj['x2']*image.width)
        y2 = int(obj['y2']*image.height)
        draw.rectangle([(x1,y1), (x2, y2)], fill=None, outline=(255,255,0,255))
        draw.text((x1+5,y1+5), obj['class'], (255,0,0))

    del draw
    return image


if __name__ == "__main__":
    
    IMAGE_URL = 'http://th-p.talk.kakao.co.kr/th/talkp/wlJX0lbRIQ/k5hNGeaLW2KLOMqzgKek3K/g95m7o_640x640_s.jpg'
    detection_result = detect_product(IMAGE_URL)
    image = show_products(IMAGE_URL, detection_result)
    image.show() 
