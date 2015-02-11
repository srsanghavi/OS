echo "enter the string you want to search for:"
read n
echo "enter file path"
read n1
if grep -q $n $n1;then
	echo "available"
else
	echo "Sorry not available"
fi
