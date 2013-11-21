#!/bin/bash

icegridadmin -u nobody -p nopass -e "node shutdown Nodo3"     --Ice.Config="config/locator.cfg"
icegridadmin -u nobody -p nopass -e "node shutdown Nodo2"     --Ice.Config="config/locator.cfg"
icegridadmin -u nobody -p nopass -e "node shutdown Nodo1"     --Ice.Config="config/locator.cfg"
