echo "How many number of terms to be calculated ?"
read n
x=0
y=1
cnt=2
echo "$x"
echo "$y"
while [ $cnt -lt $n ]
do
      z=`expr $x + $y `
      x=$y
      y=$z
      cnt=`expr $cnt + 1 `
      echo "$z"
done
