#include <stdio.h>
#include <stdbool.h>

#define FILE_PATH "script.txt"
#define CONTINUE lineCount < 20 && feof(file) == false

int main(void){
    FILE *file = fopen(FILE_PATH, "r");

    int lineCount = 0;
    char currentChar = '\0', input;
	lable1:
    do {
        currentChar = getc(file);
        if(currentChar == '\n'){
            ++lineCount;
        }
		printf("%c", currentChar);

	} while (CONTINUE);
	scanf("%s", &input);
	if (input != 'q')
		goto lable1;
	return 0;
}
