while (True):
    
    score = int(input('score: '))

    if score >= 90:
        print('A')
    elif score >= 80:
        print('B')
    elif score >= 60:
        print('C')
    elif score >= 40:
        print('D')
    elif score <= 39 and score >= 0:
        print('F')
    elif score < 0:
        break
