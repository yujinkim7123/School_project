d=[{'name':'Todd', 'phone':'555-1444', 'email':'todd@mail.net'},
   {'name':'Helga', 'phone':'555-1618', 'email':'Helga@mail.net'},
   {'name':'Princess', 'phone':'555-3141', 'email':''},
   {'name':'LJ', 'phone':'555-2718', 'email':'LJ@mail.net'}]

for dic in d:

   if dic['phone'][-1] == '8':
       print(dic['name'])

print("\n")

for dic in d:

   if dic['email'] == '':
       print(dic['name'])

print("\n")
name = input('name: ')
check = 0

for dic in d:

   if dic['name'] == name:
       check = 1
       print(dic['name'], " ",dic['phone'] ,dic['email'])


if check == 0:
    
    print("이름이 없습니다")


    
