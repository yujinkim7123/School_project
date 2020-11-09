data = {"Sun": 0, "Mon": 1, "Tue": 2, "Wed": 3,"Thu": 4, "Fri": 5, "Sat": 6}



try:
    while(True):
        s = input('input: ')
        print(data[s])
    
except KeyError:
    print("항목이 없습니다.")



    
