#include <stdio.h>

double FtoC(int degree) {
  return (degree - 32) / 1.8;
}

int main(void) {
  int input = 27;
  double newTemp = FtoC(input);
  printf("%i degrees Fahrenheit is %f degrees Celsius", input, newTemp);
  return 0;
}
