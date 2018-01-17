hours=`date|cut -c12-13`
if [ $hours -le 12 ];then
	echo "Good Morning"
else
	if [ $hours -le 16 ];then
		echo "Good Afternoon"
	elif [ $hours -le 20 ];then
		echo "Good Evening"
	else
		echo "Good Night"
	fi
fi
