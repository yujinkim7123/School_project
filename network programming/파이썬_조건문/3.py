now_hour = int(input('Enter hour: '))
ap = int(input('am (1) or pm(2)? '))
ahead = int(input('How many hours ahead? '))

new = now_hour+ahead

if ap == 2:
    new += 12

new = new%24  


if now_hour > 0 and now_hour < 13:                   

    if new >= 12:
        ap = 2
        new -= 12
    elif new < 12:
        ap = 1
else:
    print("잘못입력하였습니다.")


                
if ap == 1:
    ap = 'am'
else:
    ap = 'pm'


print("New hour: %d %s" %(new, ap))  
    
