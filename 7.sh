echo "enter jan/janu/january:"
read mon
case $mon in
	'jan') echo "january" ;;
	'janu') echo "january" ;;
	'january') echo "january" ;;
	*) echo "invalid input" ;;
esac
