# !/bin/bash
for (( c=1; c<=5; c++ ))
do 
	ARG=$(shuf -i 0-100 -n 80) && ./push_swap $ARG
done	
