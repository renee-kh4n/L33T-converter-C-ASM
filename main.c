#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 200


extern char asmfunc(char* c);

void cFunc(char* strC) {

	
	

}

void init(char* strC) {
	int i;
	for (i = 0; i < MAX; i += 10) {
		strC[i] = 0;
		strC[i + 1] = 0;
		strC[i + 2] = 0;
		strC[i + 3] = 0;
		strC[i + 4] = 0;
		strC[i + 5] = 0;
		strC[i + 6] = 0;
		strC[i + 7] = 0;
		strC[i + 8] = 0;
		strC[i + 9] = 0;
	}
}

int main() {

	clock_t start, end;
	char strC[MAX], strAsm[MAX];
	double cTime = 0, asmTime = 0;

	init(strC);

	printf("L33T Converter\n\n");

	printf("Enter a string: ");
	scanf_s(" %s", strC);						 // use scanf_s to scan the string

	strcpy_s(strAsm, sizeof(strAsm), strC);      // use strcpy_s to copy the string
	printf("Original String: %s \n\n", strAsm);

	printf("---------------C function---------------\n");
	start = clock();
	//cFunc(strC);
	asmfunc(strC);
	end = clock();
	cTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	printf("C Output: %s\n", strC);
	printf("C function time: %f ms\n\n", cTime);

	printf("-------------ASM function---------------\n");
	start = clock();
	asmfunc(strAsm);
	end = clock();
	asmTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
	printf("ASM Output: %s\n", strAsm);
	printf("ASM function time: %f ms\n\n", asmTime);


	return 0;


}