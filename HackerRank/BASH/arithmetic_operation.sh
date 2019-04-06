read -r x
printf "%.3f\n" $(echo "scale=4;$x" | bc -l)
