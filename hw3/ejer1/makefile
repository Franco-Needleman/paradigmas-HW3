make:
	g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror main.cpp -o main
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main 
	rm main