import serial
import pydirectinput
arduino = serial.Serial('COM5', 9600, timeout =.1)
pydirectinput.PAUSE = 0

keysDown = {}

def keyDown(key):
    keysDown[key] = True
    pydirectinput.keyDown(key)

def keyUp(key):
    if key in keysDown:
        del (keysDown[key])
        pydirectinput.keyUp(key)
def handleJoyStickAsArrowKeys(x,y,bx,by,bz,be):
    if y == 2:
        keyDown('up')
        keyUp('down')
    elif y == 0:
        keyDown('down')
        keyUp('up')
    else:
        keyUp('up')
        keyUp('down')
    if x == 0:
        keyDown('right')
        keyUp('left')
    elif x == 2:
        keyDown('left')
        keyUp('right')
    else:
        keyUp('left')
        keyUp('right')
    if bx == 1:
        keyDown('q')
    else:
        keyUp('q')
    if by == 1:
        keyDown('b')
    else:
        keyUp('b')
    if bz == 1:
        keyDown('d')
    else:
        keyUp('d')
    if be == 1:
        keyDown('e')
    else:
        keyUp('e')

    
while True:
    rawdata = arduino.readline()
    data = str(rawdata.decode('utf-8'))
    if data.startswith("S"):
       dx = int(data[1])
       dy  = int(data[3])
       bx = int(data[5])
       by = int(data[7])
       bz  = int(data[9])
       be = int(data[11])
       handleJoyStickAsArrowKeys(dx, dy, bx, by, bz, be)