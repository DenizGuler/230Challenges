#include <stdio.h>


struct BSTNode{
  char data[10];
  struct BSTNode *left;
  struct BSTNode *right;
};

void print_tree(const struct BSTNode *root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("\"%s\" ", root->data);
    print_tree(root->right);
  }
}


// See the README.txt file for the challenge description.
int main(void) {
  struct BSTNode head = {"apple"};
  struct BSTNode n1 = {"banana"}, n2 = {"orange"}, n3 = {"pear"}, n4 = {"peach"}, n5 = {"kiwi"};
  head.left = &n1;
  head.right = &n2;
  n1.left = &n3;
  n1.right = &n4;
  n2.left = &n5;
  print_tree(&head);
  //printf("Get to work!\n");
  return 0;
}
