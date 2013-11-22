#!/bin/bash    

. common.sh

start "$@"
exec icegridgui --Ice.Config=config/locator.cfg

