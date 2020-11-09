import sys

sum1 =0

for i in range(1,len(sys.argv)):
    sum1 = int(sys.argv[i]) + sum1


print(sum1)
