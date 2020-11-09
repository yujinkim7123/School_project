class Calculator:
    def calc(self, n, m, s):
        self.n = n
        self.m = m
        self.s = s
        
        if(self.s == 'add'):
            self.result = self.add()
        elif(self.s == 'sub'):
            self.result = self.sub()
        elif(self.s == 'mul'):
            self.result = self.mul(n,m)
        elif(self.s== 'div'):
            self.result = self.div()
            
        return self.result

    def add(self):
        return self.n + self.m
    
    def sub(self):
        return self.n - self.m
    
    def mul(self,n,m):
        return self.n * self.m
    
    def div(self):
        return self.n/self.m


res = Calculator()
print(res.calc(3, 5, "mul"))
      
