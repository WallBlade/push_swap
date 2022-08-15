# !/bin/bash
for (( c=1; c<=100; c++ ))
do 
	ARG=$(shuf -i 0-499 -n 500) && ./push_swap $ARG | ./checker_linux $ARG
	echo $ARG
	# ARG=$(shuf -i 0-499 -n 500) && ./push_swap $ARG | wc -l
done	
