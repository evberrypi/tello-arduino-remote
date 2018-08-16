This repo contains an arduino sketch which takes button input and writes to the serial port of a PC.

The PC then takes this input and uses it to control the Tello Drone.

It uses [pyserial](https://github.com/pyserial/pyserial/tree/master/examples) and [tellopy](https://github.com/hanyazou/TelloPy)

* this is a work in progress, hence the `emergencylanding.py`

Fixme's:
	- It works with an UNO, but I want to connect it to an arduino 101 to utilize the gyroscope/accelerometer for turning/throttle
