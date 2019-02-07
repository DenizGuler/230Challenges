#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// problem 1
struct Cred {
  char username[10];
  char password[10];
  struct Cred *next;
};

// problem 2
struct Cred *cred(char username[], char password[], struct Cred *link) {
    struct Cred *new_cred = NULL;
    new_cred = (struct Cred *) malloc(sizeof(struct Cred));
    // checking for issues with data allocation
    if (new_cred == NULL) {
        return NULL;
    }
    strcpy(new_cred->username, username);
    strcpy(new_cred->password, password);
    new_cred->next = link;

    return new_cred;
}

// iterates through the list and returns memory to the heap
void cred_free(struct Cred *head) {

    struct Cred *n = head;
    while(n != NULL) {
        struct Cred *n1 = n;
        n = n->next;
        free(n1);
        n1 = NULL;
    }

    free(head);

    printf("%i", sizeof(head));
}
    // struct Cred *dummy;
    // while (head != NULL) {
    //     dummy = head->next;
    //     free(head);
    //     // head = head->next;
    //     // free(dummy->next);
    //     // dummy->next = NULL;
    //     // free(dummy->password);
    //     // dummy.password = "\0";
    //     // free(dummy->username);
    //
    //     head = NULL;
        // printf("user: %s, pass: %s\n", dummy->username, dummy->password);
    // }
    // free(head);
    // head = NULL;
// }

void cred_print(struct Cred *head) {
    struct Cred *dummy = head;
    while (dummy != NULL) {
        printf("user: %s, pass: %s\n", dummy->username, dummy->password);
        dummy = dummy->next;
    }
}

int test_cred() {
    char user[] = {"user_test"}, pass[] = {"pass_test"};
    char *user_ptr = user, *pass_ptr = pass;
    struct Cred *ptr_test = cred(user, pass, NULL);

    if (strcmp(ptr_test->username, user) != 0 || strcmp(ptr_test->password, pass) != 0) {
        return 1;
    }
    return 0;
}

int test_cred_free() {
    struct Cred* a = cred("jody", "123", NULL);
    struct Cred* b = cred("hazel", "abc", a);
    struct Cred* c = cred("caleb", "xyz", b);
    cred_free(c);
    // cred_print(c);
    // if (c != NULL ){// || b != NULL || a != NULL) {
    //     return 1;
    // }
    // if (b != NULL) {
    //     return 2;
    // }
    // if (a != NULL) {
    //     return 3;
    // }
    // return 0;

    printf("cheeto: %p, lizard: %p, pitr: %p", c, b, a);

    return 0;

}



// See the README.txt file for the challenge description.
int main(void) {
    struct Cred* c = cred("caleb", "xyz",
                          cred("hazel", "abc",
                               cred("jody", "123", NULL)));
    cred_print(c);
    printf("cred_test: %i, cred_free_test: %i\n", test_cred(), test_cred_free());
    // cred_print(c);
    printf("Get to work!\n");
    return 0;
}
