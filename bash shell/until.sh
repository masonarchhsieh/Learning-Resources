#this is for until loop in action shell-script

count=1
until [ $count -gt 10 ]
do
	echo $count
	count=`expr $count + 1`
done
