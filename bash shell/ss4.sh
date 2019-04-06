#this file take a file name as an argument and renames it


echo "provide a file name"
read name
mv $1 $name 
cat $name
