echo "Please Enter a number between 50 and 100:\c"
read num

if [ $num -le 100 -a $num -ge 50 ]
then
	echo "This is the number we asked."
else
	echo "What the fuck are you doing?"
fi
