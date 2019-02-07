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

Design and implement a binary tree data structure using the C struct construct. Your binary tree must be designed to hold C strings of a reasonable length. Your struct declaration must be declared globally so that it is accessible in any function defined in the `main.c` file. The name of your struct should be `BSTNode`.

## Problem 2

Inside your `main` function use the binary tree structure you declared to manually build a binary tree containing the following strings (in no particular order):

"orange", "banana", "apple", "pear", "peach", "kiwi"

You must build your binary tree such that the fully constructed tree is balanced. You may only use static allocation for this problem and the "address of" operator.

## Problem 3

Write a function called `print_tree` that prints the contents of the tree in order (inorder traversal). The signature of this function is:

```
void print_tree(const struct BSTNode *root);
```

## Problem 4 (BONUS - if you have extra time, not required)

Write a function called `find` that traverses the binary search tree looking for a given C string. This function should return a pointer to the node in the tree that was found or NULL to indicate that no such node exists. Here is the signature of this function:

```
struct BSTNode * find(const struct BSTNode *root,
                      const char *str);
```
