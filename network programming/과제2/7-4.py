def count(n):
    list1 = []
    for i in range(1,n+1):        
        if n%i==0:
            list1.append(i)
    return list1

num = input('number: ')
list2 = count(int(num))
print(list2)
