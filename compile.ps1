gcc -ansi -I. -c node.c -o node.o
gcc -ansi -I. -c manhattan_cost.c -o manhattan_cost.o
gcc -ansi -I. -c list.c -o list.o
gcc -ansi -I. -c algorithm.c -o algorithm.o
gcc algorithm.o list.o manhattan_cost.o node.o -o algorithm