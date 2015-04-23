echo "enter a number"
read n
j=0
listvar="1 3 6 21 8 234 9 123 67 12 8"
for i in $listvar; do
    j=`expr $j + 1 `
    if [ $n == $i ]; then
    	echo $j
    fi
done
