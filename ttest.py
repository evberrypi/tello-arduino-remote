from time import sleep
import tellopy
import serial
ser = serial.Serial('/dev/ttyACM1', 9600)

def handler(event, sender, data, **args):
    drone = sender
    if event is drone.EVENT_FLIGHT_DATA:
        print(data)


def test():
    input = ser.readline()[0]
    drone = tellopy.Tello()
    try:
        drone.subscribe(drone.EVENT_FLIGHT_DATA, handler)

        drone.connect()
        drone.wait_for_connection(60.0)
        drone.takeoff()
        usebuttons()
#        drone.land()
#        sleep(30)
        print("BYE")
        #drone.down(50)
        #sleep(5)
        #drone.land()
        #sleep(5)
    except Exception as ex:
        print(ex)
        drone.quit
    finally:
        print("finally")
        #drone.quit()

def usebuttons():
    while True:
        if input == 48: # right
            drone.right(100)
            print("right")
        elif input == 49: #up
            drone.left(100)
            print("left")
        elif input == 51: #down
            drone.down(50)
            print("down")
        elif input == 54: #left
             drone.left(50)
             print("left")
        elif input == 57: #select
            print("Aye Aye Captain")
            drone.land()
            drone.quit()

if __name__ == '__main__':
    test()

