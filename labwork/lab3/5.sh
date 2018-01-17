y='y'
while [ $y == 'y' ]
do
	echo "Enter number to be squared:"
	read n
	echo $(($n * $n))
	echo "do you want to continue...[y/n]?"
	read y
done

