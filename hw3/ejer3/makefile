make:
	g++ -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast -Wcast-qual -Wlogical-op -Wredundant-decls -Wpointer-arith -Woverloaded-virtual -Werror main.cpp -o main
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main 
	rm main