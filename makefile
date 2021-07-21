#executable
run: files.o prog.o
	gcc -Wall -o run prog.o files.o -O2
	rm -f *.o



#example program
prog.o: src/prog.c src/files.h
	gcc -Wall -c src/prog.c -O2



#files library
files.o: src/files.c src/files.h
	gcc -Wall -c src/files.c -O2
