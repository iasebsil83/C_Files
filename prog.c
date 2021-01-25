// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>



//files utility
#include "files.h"




















/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prog [V.V.V] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                        files.h demonstration program

        Blablabla about the subject.

    DD/MM/YYYY > [V.V.V] :
    - Added something.
    - Added something else.

    DD/MM/YYYY > [V.V.V] :
    - Added something that wasn't before.
    - Fixed a bug.
    - Added something else.
    - Added something else again.

    BUGS : Active bugs in last version.
    NOTES : Notes.

    Contact     : 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




















// ---------------- EXECUTION ----------------

//main
int main(){
	//presentation
	printf("This is a basic example of file reading/writing using \"files.c/.h\".\n\n");
	char* data;
	size_t length;
	int error;






	//read from a text file
	printf("I.A. > Reading from text file \"examples/read.txt\"...\n");

	error = file_read("examples/read.txt", &data, &length);

	if(error)
		printf("I.A. > Error code (%i) has occured.\n\n", error);
	else{
		printf("I.A. > Text file content (between \\<-, ->/) :\n\n\\<-");
		for(size_t d=0; d < length; d++)
			printf("%c", data[d]);
		printf("->/\n\n");
	}
	free(data);






	//write into a text file
	printf("I.A. > Writing into text file \"examples/write.txt\"...\n");

	//prepare data to write
	length = 22;
	data = malloc(length+1);
	sprintf(data, "Blablabla blabla bla.\n");

	error = file_write("examples/write.txt", &data, &length);

	if(error)
		printf("I.A. > Error code (%i) has occured.\n\n", error);
	else
		printf("\nI.A. > Successfully wrote \"%s\" in text file.\n\n", data);
	free(data);






	//read from a binary file
	printf("I.A. > Reading from binary file \"examples/read.bin\"...\n");

	error = file_read("examples/read.bin", &data, &length);

	if(error)
		printf("I.A. > Error code (%i) has occured.\n\n", error);
	else{
		printf("I.A. > Binary file content (represented with 2 hexadecimal digits per byte) :\n\n");
		for(size_t d=0; d < length; d++)
			printf("%02x ", data[d] & 0xff);
		printf("\n\n");
	}






	//write into a binary file
	printf("I.A. > Writing into binary file \"examples/write.bin\"...\n");

	error = file_write("examples/write.bin", &data, &length);

	if(error)
		printf("I.A. > Error code (%i) has occured.\n\n", error);
	else
		printf("\nI.A. > Successfully wrote in binary file.\n\n");
	free(data);






	return EXIT_SUCCESS;
}
