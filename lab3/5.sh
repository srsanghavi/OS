echo "enter the total salary for the computation of HRA"
read salary
echo "enter the HRA per month"
read hra
ah=$(($hra * 12))
echo "The actual HRA received is $ah"
echo "Rent paid in excess of 10% of salary"
ss=`expr $salary / 10`
m=`expr $ah - $ss`
echo $m
echo "50% of salary"
fs=`expr $s / 2`

echo $fs
if [ $ah -le $m ]; then
	t=$ah
fi
if [ $m -le $ah ]; then
	t=$m
fi
if [ $fs < $t ]; then
	t=$fs
fi
echo "The HRA is $t"

