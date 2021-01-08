#executable
run: files.o prog.o
	gcc -Wall -o run prog.o files.o -O2
	rm -f *.o



#example program
prog.o: prog.c files.h
	gcc -Wall -c prog.c -O2



#files library
files.o: files.c files.h
	gcc -Wall -c files.c -O2
