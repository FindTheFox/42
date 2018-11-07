ifconfig -a | grep "ether" | cut -c 7- | sed 's/ //g'
