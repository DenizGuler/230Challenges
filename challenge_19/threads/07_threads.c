#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread routine prototype.
void *thread(void *vargp);

int main(int argc, char **argv) {
  pthread_t tid;
  int i;
  for (i = 0; i < 100; ++i) {
    pthread_create(&tid, NULL, thread, (void *)&i);
    // instead of detaching, wait for the thread to
    // complete before creating a new one
    pthread_join(tid, NULL);
  }
}

void *thread(void *vargp) {
  int i = *((int *)vargp);
  printf("%d\n", i);
  return NULL;
}
