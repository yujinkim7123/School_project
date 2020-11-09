
def dictre(s):
    test = dict()
    s1 = s.split('&')
    for s in s1:
         s2 = s.split('=')
         test[s2[0]]=s2[1]

    return test


s = input('Enter the string: ')


print(dictre(s))
