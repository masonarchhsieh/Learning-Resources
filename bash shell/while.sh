#this is a while-loop shell script.
count=5
while [ $count -le 10 ]
do
	echo $count
	count=`expr $count + 1`
done


