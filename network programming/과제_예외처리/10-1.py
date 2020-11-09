class Deposit :
    
    def __init__(self, initial, interest, n):
        self.initial = initial
        self.interest = interest
        self.n = n

    def profit(self):
        return int(self.initial * (1 + self.interest)**self.n)



D = Deposit(1000000,0.035,7)

print(D.profit())
