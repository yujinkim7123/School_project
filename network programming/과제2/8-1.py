x = input('some text: ')

c = 0

for i, s in enumerate(x):
    if 'a' in s:
        print(i)
        c = 1

if c == 0:
    print("a가 없습니다")
