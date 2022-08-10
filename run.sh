# !/bin/bash
for (( c=1; c<=5; c++ ))
do 
	echo "TEST : $i"
	ARG=$(shuf -i 0-50 -n 15) && ./push_swap $ARG
done	
