data = {"Sun": 0, "Mon": 1, "Tue": 2, "Wed": 3,"Thu": 4, "Fri": 5, "Sat": 6}


while(True):
    s = input('input: ')

    if s in data:
        print(data[s])
    else:
        print("항목이 없습니다.")
