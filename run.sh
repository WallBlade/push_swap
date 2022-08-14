# !/bin/bash
for (( c=1; c<=5; c++ ))
do 
	# ARG=$(shuf -i 0-99 -n 100) && ./push_swap $ARG | ./checker_linux $ARG
	ARG=$(shuf -i 0-499 -n 500) && ./push_swap $ARG | wc -l
done	
