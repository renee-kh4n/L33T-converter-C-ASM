#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//extern void asmfunc(char* str, char* str2, char* str3);

void cFunc(char* str) {

	printf("---------------C function---------------\n");
	printf("Original String: %s \n\n", str);

}

int main() {

	char str[] = { 'h', 'e', 'y', 0 };
	char orig[] = { 'a','e','i','o','u','A','E','I','O','U', 0 };
	char repl[] = { '4','3','!','0','v','4','3', '!','0','v' };
	cFunc(str);

	//asmfunc(str, orig, repl);

	printf("-------------ASM function---------------\n");
	printf("Returned String : %s \n", str);
	printf("str");
	return 0;


}