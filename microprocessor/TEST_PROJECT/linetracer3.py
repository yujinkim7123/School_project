import RPi.GPIO as GPIO
import time
from motor_test_curve_swing import AlphaBot2
from AlphaBot2.python.TRSensors import TRSensor

whl = AlphaBot2()
Button = 7
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(Button,GPIO.IN, GPIO.PUD_UP)
print("Press button to start")

TR = TRSensor()

while (GPIO.input(Button) != 0):
    time.sleep(0.05)

try:
    while True:
        sensors = TR.AnalogRead()
        middle_sensor = sensors[2]
        first_sensor = sensors[3]
        three_sensor = sensors[1]
        zero_sensor = sensors[0]
        four_sensor = sensors[4]
        print(TR.AnalogRead())

        if middle_sensor < 500:
            whl.forward() 
        elif three_sensor < 500:
            whl.left()
            if zero_sensor < 600:
                whl.left()
        elif first_sensor < 500:
            whl.right()
            if four_sensor < 600:
                whl.right()
        elif four_sensor < 500:
            whl.right() 
        elif zero_sensor < 500:
            whl.left()  

             
except:
    print("except")
    GPIO.cleanup()

