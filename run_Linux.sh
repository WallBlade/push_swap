make
echo
echo "PART 1: Memory leaks"
valgrind ./push_swap 5 1
valgrind ./push_swap 5 1 5
echo
echo "PART 2: Error management"
./push_swap er 4 lu 5
./push_swap 5 2 6 3 1 5
./push_swap 1 2147483648 3
./push_swap 1 18446744073709551615 3
./push_swap
echo
echo "PART 3: Identity test"
./push_swap 42 | wc -l
./push_swap 0 1 2 3 | wc -l
./push_swap 0 1 2 3 4 5 6 7 8 9 | wc -l
echo
echo "PART 4: Simple version"
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 0"; ./push_swap $ARG | wc -l
echo
echo "PART 5: Another simple version"
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG
./tester.sh 5
echo
echo "PART 6: Middle version"
ARG=`ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG
./tester.sh 100
echo
echo "PART 7: Advanced version"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG
./tester.sh 500
echo
echo "Visualizer algo"
python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` 
