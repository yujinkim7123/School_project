def sum1(a,b):
    return a+b

def sub1(a,b):
    return a-b

def mul1(a,b):
    return a*b

def div1(a,b):
    return a/b


fun = { '1': sum1 , '2':sub1, '3': mul1, '4': div1}


n = input('Enter the operation: ')
x = input('Enter x: ')
y = input('Enter y: ')

print(fun[n](int(x),int(y)))
