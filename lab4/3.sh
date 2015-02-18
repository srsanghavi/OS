word=$1    #shell script to accept a number and a word as command line arguments and print the word the given number of times on each line.
number=$2
i=1;
while [ $i -le $2 ]
do
echo "$word"
i=`expr $i + 1`
done

