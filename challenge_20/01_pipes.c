#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 25

int child_task(int read_pipe, int write_pipe) {
  char to_msg[25];
  char from_msg[] = "hello from child";
  int nr, nw;

  if ((nr = read(read_pipe, to_msg, 25)) == -1) {
    perror("child failed to read from pipe");
    return 1;
  }

  printf("child received message from parent.\n");
  printf("bytes: %d\n", nr);
  printf("message received: %s\n", to_msg);

  nw = write(write_pipe, from_msg, strlen(from_msg)) + 1;

  if (nw == -1) {
      perror("write");
      return 1;
  }

  return 0;
}

int parent_task(int read_pipe, int write_pipe) {

  int nw, nr;
  char to_msg[25];
  char from_msg[] = "hello from parent.";


  nw = write(write_pipe, from_msg, strlen(from_msg) + 1);

  if (nw == -1) {
    perror("parent failed to write to pipe");
    exit(1);
  }

  printf("parent sent message to child.\n");
  printf("message sent: %s.\n", from_msg);
  printf("bytes written: %d\n", nw);

  wait(NULL);

  if ((nr = read(read_pipe, to_msg, 25)) == -1) {
    perror("child failed to read from pipe");
    return 1;
  }

  to_msg[nr] = '\0';

  printf("parent recieved message from child.\n");
  printf("message recieved: %s.\n", to_msg);
  printf("bytes written: %d\n", nr);

  return 0;
}

int main() {
  int parent_to_child_pipe[2], child_to_parent_pipe[2];


  // Create the pipe
  if (pipe(parent_to_child_pipe) == -1) {
    perror("could not create pipe");
    exit(1);
  }

  if (pipe(child_to_parent_pipe) == -1) {
    perror("could not create pipe");
    exit(1);
  }

  pid_t pid;
  if ((pid = fork()) == 0) {
    // Child process...
    // First we close the write end of the pipe.
    close(parent_to_child_pipe[1]);
    close(child_to_parent_pipe[0]);
    exit(child_task(parent_to_child_pipe[READ], child_to_parent_pipe[WRITE]));
  } else {
    // Parent process...
    // First, we close the read end of the pipe.
    close(parent_to_child_pipe[0]);
    exit(parent_task(child_to_parent_pipe[READ], parent_to_child_pipe[WRITE]));

    // Wait on child process to complete
    wait(NULL);
    printf("parent process completing.\n");
  }
}
