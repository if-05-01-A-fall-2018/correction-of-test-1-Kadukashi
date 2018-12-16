#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

char* arguments[] = {"ls", NULL};
char* args[] = {"df", "ps", "pwd"};

int main(int argc, char const *argv[]) {
  int i = 0;
  while (i<4) {
    pid_t pid = fork();
    if (pid == 0) {
      arguments[0] = args[i];
      execvp(arguments[0], arguments);

      printf("fail");
    }
    else{
      int status;
      waitpid(-1, &status, 0);
    }
    i++;
  }
  printf("DONE!");
  return 0;
}
