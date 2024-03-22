#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    printf("Child process created with PID: %d\n", getpid());
    sleep(10);
    printf("Child process with PID: %d finished\n", getpid());
  } else {
    printf("Parent process with PID: %d\n", getpid());
    printf("Child process PID: %d\n", pid);
    sleep(100);
    printf("Parent process with PID: %d finished\n", getpid());
  }

  return 0;
}
