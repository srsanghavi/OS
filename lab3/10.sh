echo Enter the filename
read fil
words=`cat $fil | wc -w`
echo  words: $words 
