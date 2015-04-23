 if [ $# -gt 0 ]  #to reverse a string
then
x=`echo $1 | wc -c`
x=`expr $x - 1`
final=""
while [ $x -gt 0 ]
do
c=`echo $1 | cut -c $x`
x=`expr $x - 1`
final=$final$c
done
fi
echo Reverse string is : $final
