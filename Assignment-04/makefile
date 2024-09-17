program: inputdouble.o getdouble.o
	gcc a04.o getdouble.o -o program -lm

inputdouble.o: a04.c getdouble.h
	gcc -c a04.c

getdouble.o: getdouble.c getdouble.h
	gcc -c getdouble.c

