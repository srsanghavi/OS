echo "enter path"
read fil
echo "Do you want to change permissions for this file, 'y' to continue?"
read c
if [ $c = 'y' ];then
	echo "enter desired permissions number choice e.g. 777"
	read c
	chmod $c $fil
	echo "permissions changed"
fi

