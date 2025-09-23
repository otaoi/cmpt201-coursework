#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  size_t len = 0;
  char *buff = NULL;
  ssize_t reading;
  char *array[] = {"", "", "", "", ""};
  int i = 0;
  const char *str1 = "print";
  const char *str2 = "quit";
  while (1) {
    printf("Enter input: ");
    reading = getline(&buff, &len, stdin);

    // add to array
    array[i] = strdup(buff);
    i++;

    if (i == 5) {
      i = 0;
    }

    buff[reading - 1] = '\0';
    if (strcmp(buff, str2) == 0) {
      break;
    }
    if (strcmp(buff, str1) == 0) {
      printf("%s", array[i % 5]);
      printf("%s", array[(i + 1) % 5]);
      printf("%s", array[(i + 2) % 5]);
      printf("%s", array[(i + 3) % 5]);
      printf("%s", array[(i + 4) % 5]);
    }
  }
  // free(buff);
  for (int j = 0; j < 4; j++) {
    free(array[j]);
  }

  return 0;
}
