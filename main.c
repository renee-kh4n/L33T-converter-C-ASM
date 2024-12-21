#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 200


extern char asmfunc(char* c);

void cFunc(char* strC) {

	int i;
	char c;
	for (i = 0; i < strlen(strC); i++) {
		c = strC[i];

		if (c == 'a' || c == 'A') {
			strC[i] = '4';
		}
		else if (c == 'e' || c == 'E') {
			strC[i] = '3';
		}
		else if (c == 'i' || c == 'I') {
			strC[i] = '!';
		}
		else if (c == 'o' || c == 'O') {
			strC[i] = '0';
		}
		else if (c == 'u' || c == 'U') {
			strC[i] = 'V';
		}

	}

	
	

}

void init(char* str) {
	int i;
	for (i = 0; i < MAX; i += 10) {
		str[i] = 0;
		str[i + 1] = 0;
		str[i + 2] = 0;
		str[i + 3] = 0;
		str[i + 4] = 0;
		str[i + 5] = 0;
		str[i + 6] = 0;
		str[i + 7] = 0;
		str[i + 8] = 0;
		str[i + 9] = 0;
	}
}

int main() {

	clock_t start, end;
	char str[MAX], strC[MAX], strAsm[MAX];
	double cTime = 0, asmTime = 0;

	//initialize strings
	init(str);
	init(strC);
	init(strAsm);

	//prompt the user
	printf("L33T Converter\n\n");

	printf("Enter a string: ");
	scanf_s("%199s", strC, (unsigned)_countof(strC)); // use scanf_s to scan the string

	strcpy_s(strAsm, sizeof(strAsm), strC);			  // use strcpy_s to copy the string
	printf("Original String: %s \n\n", strAsm);

	//call the C function
	printf("---------------C function ---------------\n");
	start = clock();
	cFunc(strC);
	end = clock();
	cTime = (double)(end - start) * 100000 / CLOCKS_PER_SEC;
	printf("C Output: %s\n", strC);
	printf("C function time: %f ms\n\n", cTime);

	//call the ASM function
	printf("-------------ASM function---------------\n");
	start = clock();
	asmfunc(strAsm);
	end = clock();
	asmTime = (double)(end - start) * 100000 / CLOCKS_PER_SEC;
	printf("ASM Output: %s\n", strAsm);
	printf("ASM function time: %f ms\n\n", asmTime);


	return 0;


}