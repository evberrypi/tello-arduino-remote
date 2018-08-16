import tellopy
import serial
ser = serial.Serial('/dev/ttyACM1', 9600)
while True:
  #read data from arduino
    input = ser.readline()[0]
    # cast the input into commands for the drone
    #print(input)
    if input == 48:
        print("right")
    elif input == 49:
        print("up")
    elif input == 51:
        print("down")
    elif input == 54:
        print("left")
    elif input == 57:
        print("select")
