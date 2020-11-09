from random import randint

money = 50

while money >= 0:
    if money < 100:
        coin = randint(1,2)
        guess = int(input('Enter your guess(1,2): '))
        if guess == 1 or guess == 2:
            if coin == guess:              
                money += 9
                print('맞았습니다', money, '$남았습니다.')
            else :
                money -= 10
                print('틀렸습니다', money, '$남았습니다.')
        else:
             print('다시 입력하세요')

    else:
        break;
         
if money <= 0:
    print('당신이 졌습니다. 돈이 없습니다.')

elif money >=100:
    print('당신이 이겼습니다.' , money ,'$남았습니다.')

    
    


    
