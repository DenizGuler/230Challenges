# README

## Instructions

You are allowed to work in groups of up to 3 people to complete this challenge. After you have completed the challenge you must submit your work to Gradescope. To do this you must download your code from repl.it. To do this look for the three vertical dots to the left of this file near the add folder icon. Clicking on this will allow you to download your work as a zip file. You must submit that zip file to the associated assignment in Gradescope. Only 1 person in the group needs to submit the zip file to Gradescope, however, you need to make sure you add everyone in your group to the submission after it has been submitted.

## Testing

For each function you need to write, you are to write at least one test function. A test function returns 0 if the test passed and 1 if it did not pass. The body of a test function should test one or more aspects of each problem you are trying to solve. Here is an example of a test function asserting that the result of calling a function called `problem` for a pretend problem we are trying to solve rotates the values in that array by 1 to the left:

```
int test_problem() {
  char word[] = "cat";
  problem(word);
  if (word[0] == 'a' && word[1] == 't' && word[2] == 'c' &&
      word[3] == '\0') {
    return 0;
  } else {
    return 1;
  }
}
```

Inside you main function you would execute the test:

```
if (test_problem() == 1) {
  printf("test_problem() FAILED\n");
}
```

## Problem 1

Design and implement a C struct representing a linked list of credentials: user names and passwords (both C strings). You must use a C struct to do this and your struct must contain a field that is a pointer to the next struct. You must name this struct `Cred`.

No test function required for this problem.

## Problem 2

Write a function to create new `Cred` structs. The function includmust be named `cred` and it should have three arguments. The first argument is the username, the second is the password, and the third is a pointer to another struct Cred. After you do this, write the following code in your main function to make sure it compiles:

```
struct Cred* c = cred("caleb", "xyz",
                      cred("hazel", "abc",
                           cred("jody", "123", NULL)));
```

You may use the C library routines found in the string.h header file called `strncpy` and `strlen` to implement this function.

Write a test function for this function. How might you do this?

## Problem 3

Write a function called `cred_free` that frees/deallocates the memory associated with each dynamically allocated `struct Cred` that was allocated with `malloc`. Your function must take as its argument a `struct Cred*`. Make sure your function is capable of deallocating an entire linked list of credentials.

Write a test function for this function. How might you do this? Can you be sure that you deallocated memory properly?

## Problem 4 (BONUS - if you have extra time, not required)

Write a function called `cred_print` that prints the list of credentials. Try this function out to make sure it works properly. It should print out the credentials from the beginning to the end of the list.

No test function required for this problem.

## Problem 5 (BONUS - if you have extra time, not required)

Write a function called `cred_add` that inserts a new credential to a linked list of credentials. This function should return a pointer to the first node in the credential linked list.

Write a test function for this function. How might you do this?
