echo Enter the filename
read fil
n=`grep -c ' ' $fil`
echo Number of spaces in $fil is $n
