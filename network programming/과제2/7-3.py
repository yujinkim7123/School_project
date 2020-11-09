def strma(s1,s2):

    
   for i,(ss1,ss2) in enumerate(zip(s1,s2)): 

       if ss1 != ss2:
           return i

   if len(s1) > len(s2):
        
        return len(s2)
    
   elif len(s1) < len(s2):
        return len(s1)

   return -1

str1 = input('string1: ')
str2 = input('string2: ')

re = strma(str1,str2)

print(re)
