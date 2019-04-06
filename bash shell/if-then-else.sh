echo "enter source and target file names."
read source target
if mv $source $target
then
	echo "Your file has been successfully renamed."
	clear
else
	echo "The file could not be renamed."
fi

