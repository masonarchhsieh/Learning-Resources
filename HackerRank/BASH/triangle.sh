read l1
read l2
read l3

if [ "$l1" -eq "$l2" ] && [ "$l2" -eq "$l3" ]; then
    echo "EQUILATERAL";
elif [ "$l1" -eq "$l2" ] || [ "$l2" -eq "$l3" ] || [ "$l1" -eq "$l3" ]; then
    echo "ISOSCELES";
else
    echo "SCALENE";
fi


