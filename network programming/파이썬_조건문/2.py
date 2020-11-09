score = int(input('성적을 입력하세요: '))

if 0 <= score:
    if score >= 40 :
        if score >= 80:
            print("졸업반입니다.")
        else:
            print("2학년입니다.")
    else:
        print("1학년입니다.")
        
