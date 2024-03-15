#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    printf("Child process\n");
    sleep(5);
    printf("Child process exiting\n");
  } else {
    printf("Parent process\n");
    sleep(120);
  }

  return 0;
}
