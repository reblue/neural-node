main: main.c percept.c node.c
	gcc -o main -g -Wall node.c percept.c main.c