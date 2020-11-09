days = {'January' : 31, 'February':28, 'March':31 , 'Aprill':30,'May':31,'June':30,
        'August':31,'September':30,'October':31,'November':30,'December':31}


month = input('month: ')

print(days[month],"\n")

print(sorted(days),"\n")


for month, days in days.items():
    if days == 31:
        print(month)
