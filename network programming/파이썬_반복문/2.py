
number1 = int(input('number1: '))
number2 = int(input('number2: '))

if number1 < number2 :
    small = number1
    big = number2

else:
    small = number2
    big = number1

result = 0

while small > 0:
    result = big%small
    big = small
    small = result

print(big)
