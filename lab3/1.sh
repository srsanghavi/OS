y='y'
while [ $y == 'y' ]
do
	echo "Enter number to be squared:"
	read n
	if [ $n -gt 50 ]; then
    		echo "nuber should be less than 50..."
	else 
		echo $(($n * $n))
	fi
	echo "do you want to continue...[y/n]?"
	read y
done

