#tut link: https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average/forum/comments/133151

read num
arr=($(cat))
arr=${arr[*]}
printf "%.3f" $(echo $((${arr// /+}))/$num | bc -l)
