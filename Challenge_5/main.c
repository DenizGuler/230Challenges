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

// problem 3
void cred_free(struct Cred *head) {
    struct Cred *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
}

// problem 4
void cred_print(struct Cred *head) {
    struct Cred *dummy = head;
    while (dummy != NULL) {
        printf("user: %s, pass: %s\n", dummy->username, dummy->password);
        dummy = dummy->next;
    }
}

// problem 5
struct Cred *cred_add(struct Cred *head, char username[], char password[]) {
    struct Cred *dummy = head;
    while (dummy->next != NULL) {
        dummy = dummy->next;
    }
    struct Cred *new_cred = cred(username, password, NULL);
    dummy->next = new_cred;
    return head;
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

// the contents of the pointer are uncertain after free is called, therefore
// we believe that there is no definitive way to check if memory has been
// successfully deallocated. This test fails constantly 
int test_cred_free() {
    struct Cred* a = cred("jody", "123", NULL);
    struct Cred* b = cred("hazel", "abc", a);
    struct Cred* c = cred("caleb", "xyz", b);
    cred_free(c);

    if (c == NULL) {
        return 0;
    }
    return 1;

}

int test_cred_add() {
    struct Cred* c = cred("a", "b",
                          cred("c", "d",
                               cred("e", "f", NULL)));
    struct Cred *dummy = c;
    // evaluates the size of the linked list before insertion
    while (dummy->next != NULL) {
        dummy = dummy->next;
    }
    c = cred_add(c, "g", "h");

    // after insertion, dummy points to the second-to-last node. This checks that the next
    // node is indeed the one that was inserted
    if (strcmp(dummy->next->username, "g") == 0 && strcmp(dummy->next->password, "h") == 0) {
        return 0;
    }
    return 1;
}

// See the README.txt file for the challenge description.
int main(void) {
    struct Cred* c = cred("caleb", "xyz",
                          cred("hazel", "abc",
                               cred("jody", "123", NULL)));
    // tests
    printf("cred_test: %i, test_cred_add: %i\n", test_cred(), test_cred_add());
    printf("test_cred_free: %i\n", test_cred_free());

    cred_print(c);
    return 0;
}
