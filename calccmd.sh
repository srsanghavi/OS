if [ $# -lt 3 ] ; then
	echo "enter two numbers followed by operator"
else
	n1=$1
	n2=$2
	if [ $3 = '+' ] ; then
		echo $(($n1 + $n2))
	elif [ $3 = '-' ] ; then
		echo $(($n1 - $n2))
	elif [ $3 = 'X' ] ; then
		echo $(($n1 * $n2))
	elif [ $3 = '/' ] ; then
		echo $(($n1 / $n2))
	fi
fi
