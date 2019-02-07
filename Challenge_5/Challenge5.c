#include <stdio.h>
#include <string.h>

// problem 1
struct Cred {
  char username;
  char password;
  struct *Cred next;
};

// problem 2
/*
 The first argument is the username, the second is the password, and the third is a pointer to another struct Cred.
*/

struct Cred* cred(char username[], char password[], struct Cred *link) {

}



// See the README.txt file for the challenge description.
int main(void) {
  printf("Get to work!\n");
  return 0;
}
