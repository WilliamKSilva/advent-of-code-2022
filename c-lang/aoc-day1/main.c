#include <stdio.h>
#include <stdlib.h>

void readDataFromInput(FILE* fp, char* buff) {
  fp = fopen("../../c-lang/aoc-day1/input.txt", "r");

  if (fp == NULL) {
    perror("teste");
    exit(1);
  }

  int prev = fseek(fp, 0, SEEK_END);

  int size = ftell(fp);

  fseek(fp, prev, SEEK_SET);

  buff = (char*)malloc(size * sizeof(char));

  fgets(buff, size, fp);

  printf("%s", buff);
  free(buff);
}

int main() {
  FILE* fp = NULL;
  char* buff = NULL;

  readDataFromInput(fp, buff);

  return 0;
}