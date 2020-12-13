#define SIMPLETEST1

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include"LASAalloc.h"

#ifdef SIMPLETEST1

int main() {

    LASAalloc lasa;

    char* array = (char*)lasa.lalloc(10);
    if (!array) {
        fprintf(stderr,"call to lasa.lalloc() failed\n");
        fflush(stderr);
        exit(1);
    }

    for (int i=0; i < 9; i++) array[i] = 'a' + i;
    array[9] = 0;

    std::cout << "here is my nifty new string:\n" << array << '\n';

    lasa.lfree(array);
    return 0;
}


#endif //SIMPLETEST1

#ifdef SIMPLETEST2

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

//#include "LasaLib.h"

int main() {
	LASAalloc lasa;

	char* a1 = (char*)lasa.lalloc(128);
	if (!a1) {
		fprintf(stderr,"call to lasa.lalloc(128) failed\n");
		fflush(stderr);
		exit(1);
	}

	std::cout<<"FREE LIST after malloc(128)\n\n";
	lasa.display();

	char* a2 = (char*)lasa.lalloc(32);
	if (!a2) {
		fprintf(stderr,"first call to lasa.lalloc(32) failed\n");
		fflush(stderr);
		exit(1);
	}

	std::cout<<"FREE LIST after malloc(32)\n\n";
	lasa.display();

	lasa.lfree(a1);

	std::cout << "FREE LIST after free of first 128 malloc()\n\n";
	lasa.display();

	char* a3 = (char*)lasa.lalloc(104);
	if (!a3) {
		fprintf(stderr,"call to lasa.lalloc(104) failed\n");
		fflush(stderr);
		exit(1);
	}

	std::cout << "FREE LIST after malloc(104)\n\n";
	lasa.display();

	char* a4 = (char*)lasa.lalloc(8);
	if (!a4) {
		fprintf(stderr,"call to lasa.lalloc(8) failed\n");
		fflush(stderr);
		exit(1);
	}
	std::cout << "FREE LIST after malloc(8)\n\n";
	lasa.display();

	lasa.lfree(a2);
	lasa.lfree(a3);
	lasa.lfree(a4);
	std::cout << "FREE LIST after all free\n\n";
	lasa.display();

	return 0;
}

#endif	//ACTIVE