# include<stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	
    for (char **envptr = envp; envptr != NULL; ++envptr) {
        puts(*envptr);
    }

	return 0;
} 
