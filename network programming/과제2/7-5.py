def sum2(n):
    if n==1:
        return 1
    else:
        return n+sum2(n-1)


print(sum2(100))
