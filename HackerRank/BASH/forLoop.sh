even=2
for i in `seq 1 100`;
do
    if (($i % $even));
    then 
        echo "$i"
    fi
done
