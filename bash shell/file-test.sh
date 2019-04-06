echo "Enter a name:\c"
read fname
if [ -s $fname ]
then
	echo "You indeed entered a file name."
else
	echo "Don't provide me crazy inputs."
fi
