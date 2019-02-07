#include <stdio.h>

// See the README.txt file for the challenge description.

struct time {
  int hours;
  int minutes;
  int seconds;
};

struct time elapsed_time(struct time t1, struct time t2) {
  struct time elapsed = {0, 0, 0};
  int total_time1, total_time2, difference;

  // conversion to circumvent times crossing midnight
  total_time1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
  total_time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
  difference = total_time2 - total_time1;

  if (difference < 0) {
    difference += 24 * 3600;
  }

  // assign hours, minutes, and seconds params
  elapsed.hours = difference / 60 / 60;
  elapsed.minutes = difference / 60 % 60;
  elapsed.seconds = difference % 60;

  return elapsed;
}

void removeString (char str[], int index, int num_chars) {
  for (int i = index; str[i] != '\0';) {
    str[i++] = str[i + num_chars];
  }
}

int main(void) {
  struct time t1 = {3,45,15}, t2 = {9, 44, 03};
  struct time elapsed = elapsed_time(t1, t2);
  printf("%i:%i:%i\n", elapsed.hours, elapsed.minutes, elapsed.seconds);

  char example[] = "the wrong son";
  removeString(example, 4, 6);
  printf("%s", example);
  return 0;
}