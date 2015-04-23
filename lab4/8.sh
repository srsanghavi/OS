echo Enter the filename
read fil
n=`grep -c '\n' $fil`
echo Number of new line characters in $fil is $n
