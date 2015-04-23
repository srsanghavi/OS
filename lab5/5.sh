echo "Enter the filename1"
read file1
echo "Enter the filename2"
read file2
if  test -s "$file1" 
then 
    echo "found the first file"
else 
    echo "first file not there"
fi

if  test -s "$file2" 
then 
    echo "found the second file"
    cat $file1 >> $file2
    echo " the contents have been appended"
else 
    echo "The file didnt exist therefore creating it"
    touch $file2
    cat $file1 >> $file2
    
fi
