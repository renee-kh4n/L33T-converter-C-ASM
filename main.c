#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern char asmfunc(char c);

void cFunc(char str) {

	printf("---------------C function---------------\n");
	printf("Original String: %c \n\n", str);

}

int main() {

	//char str[] = { 'h', 'e', 'y', 0 };
	//char orig[] = { 'a','e','i','o','u','A','E','I','O','U', 0 };
	//char repl[] = { '4','3','!','0','v','4','3', '!','0','v' };
	char c = 'a';
	cFunc(c);

	char d = asmfunc(c);

	printf("-------------ASM function---------------\n");
	printf("Returned String : %c \n", d);
	printf("str");
	return 0;


}