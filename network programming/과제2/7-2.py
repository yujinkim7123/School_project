def num1(n):
   s = str(n)
   sums = 0
   munl = 1
   for c in s:
       sums = int(c) + sums
       munl = int(c)*munl
       
   return sums, munl


num = input("input number: ")

sum1, munl2 = num1(num)

print(sum1, munl2)
