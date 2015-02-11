echo "Enter a number: "
read n
i=2
flag=0
while [ $i -le `expr $n / 2` ]
	do
		if [ `expr $n % $i` == 0 ];then
			flag=1
		fi
		i=`expr $i + 1`
	done
if [ $flag == 1 ];then
	echo "The number is not prime"
else
	echo "The number is Prime"
fi
