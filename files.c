// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>



//own header
#include "files.h"




















/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Files [0.1.1] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                            File Read Write by I.A.

        FRW is just an utility program that allows you to manipulate files
    more simply than stdio.h does.

    You can now read or write into a file in only one line.

    This program only adds 2 functions :
     - FRW_read()
     - FRW_write()

    02/10/2020 > [0.1.0] :
    - Created FRW.c/.h.

    07/01/2021 > [0.1.1] :
    - Added a header file (in order to use it as a library).
    - Removed binary/text mode selection.
    - Changed prototypes to allow FRW_read() to return also data length.
    - Fixed writing bug in binary files.
    - Renamed library from "FRW" to "files".
    - Added demonstration program.

    BUGS : .
    NOTES : files_write() doesn't use '\0' as a stop character to allow
            users to write all kind of character in file.
            Therefore, binary files can be wrote from text data without
            giving importance to '\0'.

    Contact     : i.a.sebsil83@gmail.com
    Youtube     : https://www.youtube.com/user/IAsebsil83
    GitHub repo : https://github.com/iasebsil83

    Let's Code !                                  By I.A.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




















// ---------------- READ / WRITE ----------------
int file_read(char* path, char** data, size_t* length){ // reads from file #path#
                                                        // output data into #data#
	//incorrect path                                // and data length into #length#
	if(path == NULL){                               // WARNING ! Value inside data should not refer to anything.
		printf("RUNTIME ERROR > files.c : file_read() : "); //                          (can refer to NULL)
		printf("Path is NULL.\n");
		return FILES__PATH_IS_NULL;
	}

	//opening file
	FILE* f = fopen(path,"rb");
	if(f == NULL){
		printf("RUNTIME ERROR > files.c : file_read() : ");
		printf("No file \"%s\" found.\n", path);
		return FILES__NO_FILE_FOUND;
	}

	//get file length
	fseek(f, 0L, SEEK_END);
	*length = ftell(f);

	//prepare data reception
	*data = malloc(*length);
	size_t d=0;
	for(; d < *length; d++)
		(*data)[d] = '\0';
	d=0;

	//read from file
	int c='_';
	fseek(f, 0L, SEEK_SET); //<=> rewind(f);
	while( (c = fgetc(f)) != EOF )
		(*data)[d++] = (char)c;
	fclose(f);

	return FILES__SUCCESS;
}

int file_write(char* path, char** data, size_t* length){ // writes into file #path#
                                                         // data from #data#
	//incorrect path                                 // from index 0 to #length#
	if(path == NULL){                                // WARNING ! Value inside data will not be free.
		printf("RUNTIME ERROR > files.c : file_write() : ");
		printf("Path is NULL.\n");
		return FILES__PATH_IS_NULL;
	}

	//incorrect data
	if(data == NULL || *data == NULL){
		printf("RUNTIME ERROR > files.c : file_write() : ");
		printf("Cannot write NULL data.\n");
		return FILES__DATA_IS_NULL;
	}

	//openning - creating file
	FILE* f = fopen(path, "wb");

	//write into file
	for(size_t d=0; d < *length; d++){
		if( fputc( (*data)[d], f) == EOF ){
			printf("RUNTIME ERROR > files.c : file_write() : Error when writing into file \"%s\".\n", path);
			return FILES__WRITING_ERROR;
		}
	}
	fclose(f);

	return FILES__SUCCESS;
}
