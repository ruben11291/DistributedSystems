#!/bin/bash    

make clean;make

icegridgui --Ice.Config=config/locator.cfg &

icegridnode --Ice.Config=config/nodo1.cfg &
echo "nodo1 up"
icegridnode --Ice.Config=config/nodo2.cfg &
echo "nodo2 up"

icegridnode --Ice.Config=config/nodo3.cfg &
echo "nodo3 up"





