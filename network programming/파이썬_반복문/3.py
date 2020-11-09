n = int(input('number: '))

for i in range(2, n+1):
    c = 1
    for j in range(2, i+1):
        if i == j :
            continue
        elif i%j == 0:
            c = 0
            break
    if c == 1:
        print(i)
    
