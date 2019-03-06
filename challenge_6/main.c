#include <stdio.h>
#include <stdbool.h>

#define FILE_PATH "script.txt"
#define CONTINUE line_count < 20 && !feof(file)// || getchar() == 'q'

int main(void){
    FILE *file = fopen(FILE_PATH, "r");

<<<<<<< HEAD
    int line_count;
    char current_char = '\0', input;
=======
    int lineCount = 0;
    int currentChar;
    char input;
>>>>>>> 2619ef305acd88dc0489325508c5c59bd635fcf3
	lable1:
	line_count = 0;
    do {
        current_char = getc(file);
        if(current_char == '\n'){
            ++line_count;
        }
		printf("%c", current_char);
	} while (CONTINUE);
	if (getchar() != 'q'){
	   goto lable1;
   }
	return 0;
}
