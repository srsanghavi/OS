read n
if ls $n &> /dev/null; then
    echo "files do exist"
else
    echo "files do not exist"
fi
