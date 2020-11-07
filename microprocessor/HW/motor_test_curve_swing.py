import RPi.GPIO as GPIO
import time

class AlphaBot2(object):

    def __init__(self,ain1=12,ain2=13,ena=6,bin1=20,bin2=21,enb=26):
        self.AIN1 = ain1    # backward signal of left wheel
        self.AIN2 = ain2    # forward signal of left wheel
        self.BIN1 = bin1    # backward signal of right wheel
        self.BIN2 = bin2    # forward signal of right wheel
        self.ENA = ena      # enable signal of left wheel
        self.ENB = enb      # enable signal of right wheel
        self.PA  = 50   # speed of left wheel
        self.PB  = 50   # speed of right wheel

        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        GPIO.setup(self.AIN1,GPIO.OUT)
        GPIO.setup(self.AIN2,GPIO.OUT)
        GPIO.setup(self.BIN1,GPIO.OUT)
        GPIO.setup(self.BIN2,GPIO.OUT)
        GPIO.setup(self.ENA,GPIO.OUT)
        GPIO.setup(self.ENB,GPIO.OUT)
        self.PWMA = GPIO.PWM(self.ENA,500)
        self.PWMB = GPIO.PWM(self.ENB,500)
        self.PWMA.start(self.PA)
        self.PWMB.start(self.PB)
        self.stop()

    def forward(self):
        self.PWMA.ChangeDutyCycle(self.PA)
        self.PWMB.ChangeDutyCycle(self.PB)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.HIGH)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.HIGH)

    def stop(self):
        self.PWMA.ChangeDutyCycle(0)
        self.PWMB.ChangeDutyCycle(0)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.LOW)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.LOW)

    def backward(self):
        self.PWMA.ChangeDutyCycle(self.PA)
        self.PWMB.ChangeDutyCycle(self.PB)
        GPIO.output(self.AIN1,GPIO.HIGH)
        GPIO.output(self.AIN2,GPIO.LOW)
        GPIO.output(self.BIN1,GPIO.HIGH)
        GPIO.output(self.BIN2,GPIO.LOW)

    def left(self):
        self.PWMA.ChangeDutyCycle(25)
        self.PWMB.ChangeDutyCycle(25)
        GPIO.output(self.AIN1,GPIO.HIGH)
        GPIO.output(self.AIN2,GPIO.LOW)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.HIGH)

    def right(self):
        self.PWMA.ChangeDutyCycle(25)
        self.PWMB.ChangeDutyCycle(25)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.HIGH)
        GPIO.output(self.BIN1,GPIO.HIGH)
        GPIO.output(self.BIN2,GPIO.LOW)

    def Swingturn(self):
        self.PWMA.ChangeDutyCycle(25)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.HIGH)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.LOW)

    def Swingturn2(self):
        self.PWMB.ChangeDutyCycle(25)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.LOW)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.HIGH)

    def Curveturn(self):
        self.PWMA.ChangeDutyCycle(25)
        self.PWMB.ChangeDutyCycle(50)
        GPIO.output(self.AIN1,GPIO.LOW)
        GPIO.output(self.AIN2,GPIO.HIGH)
        GPIO.output(self.BIN1,GPIO.HIGH)
        GPIO.output(self.BIN2,GPIO.LOW)    
 
    def Curveturn2(self):
        self.PWMA.ChangeDutyCycle(50)
        self.PWMB.ChangeDutyCycle(25)
        GPIO.output(self.AIN1,GPIO.HIGH)
        GPIO.output(self.AIN2,GPIO.LOW)
        GPIO.output(self.BIN1,GPIO.LOW)
        GPIO.output(self.BIN2,GPIO.HIGH)


    def setPWMA(self,value):
        self.PA = value
        self.PWMA.ChangeDutyCycle(self.PA)

    def setPWMB(self,value):
        self.PB = value
        self.PWMB.ChangeDutyCycle(self.PB)

    
if __name__=='__main__':

    Ab = AlphaBot2()
    #Ab.forward()
    #time.sleep(3)
    #Ab.left()
    #time.sleep(3)
    #Ab.right()
    #time.sleep(3)
    #Ab.backward()
    #time.sleep(3)
    #Ab.forward()
    Ab.Swingturn()
    time.sleep(3)
    Ab.Swingturn2()
    time.sleep(3)
    Ab.Curveturn()
    time.sleep(3)
    Ab.Curveturn2()
    

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()
