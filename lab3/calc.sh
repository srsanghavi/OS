read n1
read n2
echo "sum is" `expr $n1 + $n2`
echo "multiplication is" "$(($n1 * $n2))"
echo "division is" `expr $n1 / $n2`
echo "substraction is" `expr $n1 - $n2`
