start_node() {
   
    echo "Starting nodo${1}"
    icegridnode --nochdir --daemon --pidfile "log/nodo${1}.pid" \
	--Ice.Config="config/nodo${1}.cfg"
}

stop_node() {
    echo "Stopping nodo${1}"
    if [ -f "log/nodo${1}.pid" ]; then
	icegridadmin -u nobody -p nopass -e "node shutdown Nodo${1}" \
	    --Ice.Config="config/locator.cfg"
	rm -f "log/nodo${1}.pid"
    fi
}

clean_node() {
    echo "Cleaning nodo${1}"
    rm -rf data/"nodo${1}"/*
    rm -f "log/out-nodo${1}.log" "log/err-nodo${1}.log"
}

start() {
    if [ $# -gt 0 ] ; then
	for i in "$@" ; do
	    start_node $i
	done
    else
	for i in 1 2 3 ; do
	    start_node $i
	done
    fi
}

stop() {
    if [ $# -gt 0 ] ; then
	for i in "$@" ; do
	    stop_node $i
	done
    else
	for i in 3 2 1 ; do
	    stop_node $i
	done
    fi
}

clean() {
    if [ $# -gt 0 ] ; then
	for i in "$@" ; do
	    clean_node $i
	done
    else
	for i in 1 2 3 ; do
	    clean_node $i
	done
	rm -rf log
    fi
    rm -rf data/registry/*
}
