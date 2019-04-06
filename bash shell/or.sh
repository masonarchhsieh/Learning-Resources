echo "enter a lower character:\c"
read var
if [ `echo $var | wc -c` -eq 2 ]
then
	if [ $var = a -o $var = e -o $var = i -o $var = o -o $var = u ]
	then
		echo "you entered a vowel."
	else
		echo "you didn't enter a vowel"
	fi		
else
	echo "Invalid input."
fi
