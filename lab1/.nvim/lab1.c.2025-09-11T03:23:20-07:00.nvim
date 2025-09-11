#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  char *token;
  char *saveptr;
  char *delimt = " ";
  size_t size = 0;
  printf("Please enter some text: ");
  char readline = getline(&buff, &size, stdin);
  if (readline == -1) {
    free(buff);
    perror("getline did not work");
    exit(EXIT_FAILURE);
  }
  printf("Tokens:");
  token = strtok_r(buff, delimt, &saveptr);
  printf("\t%s\n", token);
  while (true) {
    token = strtok_r(NULL, delimt, &saveptr);
    if (token == NULL) {
      break;
    }
    printf("\t%s\n", token);
  }
  free(buff);
  exit(EXIT_SUCCESS);
}
