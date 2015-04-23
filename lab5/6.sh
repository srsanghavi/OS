numb=$1
i=1
b=50
if [ $numb -le 50 ]; then
n=50
fi
if [ $numb -ge 50 ]; then
n=$1
fi

while [ $i -le $n ]
do
j=`expr $i \* $i`
echo "$j"
i=`expr $i + 1`
done

