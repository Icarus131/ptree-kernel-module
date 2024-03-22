#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;

  // Fork a child process
  pid = fork();

  if (pid < 0) {
    // Fork failed
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    // Child process
    printf("Child process created with PID: %d\n", getpid());
    // Child process runs for a while
    sleep(10);
    printf("Child process with PID: %d finished\n", getpid());
  } else {
    // Parent process
    printf("Parent process with PID: %d\n", getpid());
    printf("Child process PID: %d\n", pid);
    // Parent process waits for child process to finish
    sleep(100);
    printf("Parent process with PID: %d finished\n", getpid());
  }

  return 0;
}
