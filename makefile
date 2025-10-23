#executable
run: files.o main.o
	gcc -Wall -o run main.o files.o -O2
	rm -f *.o



#example program
main.o: src/main.c lib/files.h
	gcc -Wall -c src/main.c -O2



#files library
files.o: lib/files.c lib/files.h
	gcc -Wall -c lib/files.c -O2
