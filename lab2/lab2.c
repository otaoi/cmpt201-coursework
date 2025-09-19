#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t newprog;
  size_t len = 0;
  int wstatus;
  char *buff = NULL;
  ssize_t reading;
  while (1) {
    printf("Enter programs to run.\n");
    reading = getline(&buff, &len, stdin);

    // remove the trailing \n like this
    buff[reading - 1] = '\0';

    newprog = fork();
    if (newprog == 0) { // this is child
      execl(buff, buff, (char *)NULL);
      printf("Exec failure\n");
    } else { // this is parent
      waitpid(newprog, &wstatus, 0);
    }
  }
}
