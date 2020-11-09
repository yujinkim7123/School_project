str2 =  input('Your word: ')

word = str2.find('a')

while(True):

    if word != -1:

        str1 = str2[:word+1]
        str2 = str2[word +1 :]

        print(str1)
        print(str2)

        word = str2.find('a')
    
        
    else:
        break
