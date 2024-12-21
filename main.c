#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern void asmfunc(char* str);

void cFunc(char* str) {

	printf("---------------C function---------------\n");
	printf("Original String: %s", str);

}

int main() {

	char* str = "Hello World!";
	cFunc(str);
	asmfunc(str);
	return 0;


}