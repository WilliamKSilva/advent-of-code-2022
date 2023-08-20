#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct String {
  int size;
  char *content;
};

// NEED TO MAKE A GENERIC STRUCT AAAAAAAA
struct IntArray {
  int size;
  int *content;
};

struct String readInputText(FILE *file) {
  struct String fileData;
  char *fileContent = NULL;

  file = fopen("./input.txt", "r");

  fseek(file, 0L, SEEK_END);
  int fileSize = ftell(file);
  rewind(file);

  fileContent = malloc(fileSize * sizeof(char));

  fread(fileContent, 1, fileSize, file);

  fileData.size = fileSize;
  fileData.content = fileContent;

  return fileData;
}

char compareRuckSackCompartments(struct String rucksack) {
  int firstHalfStart = 0;
  int secondHalfStart = (rucksack.size / 2) - 1;

  char matchValue;

  for (int i = 0; i <= secondHalfStart; i++) {
    int firstCompartmentValue = rucksack.content[i];

    for (int j = secondHalfStart + 1; j < rucksack.size; j++) {
      int secondCompartmentValue = rucksack.content[j];

      if (firstCompartmentValue == secondCompartmentValue) {
        matchValue = secondCompartmentValue;
      }
    }
  }

  return matchValue;
}

struct String loopRuckSacks(struct String listItems) {
  struct String rucksack = {.size = 0, .content = NULL};
  struct String matchArray = {.size = 0, .content = NULL};

  for (int i = 0; i < listItems.size; i++) {
    char currentChar = listItems.content[i];

    // printf("%d", sumValue);
    // printf("%s", "\n\n");

    if (currentChar == '\n') {
      char matchValue = compareRuckSackCompartments(rucksack);

      // printf("%c", matchValue);
      // printf("%s", "\n\n");

      matchArray.size = matchArray.size + 1;

      matchArray.content =
          realloc(matchArray.content, matchArray.size * sizeof(char));

      matchArray.content[matchArray.size - 1] = matchValue;

      rucksack.size = 0;
      free(rucksack.content);
      rucksack.content = NULL;

      continue;

    } else {
      rucksack.size = rucksack.size + 1;

      rucksack.content =
          realloc(rucksack.content, rucksack.size * sizeof(char));

      rucksack.content[rucksack.size - 1] = listItems.content[i];

      continue;
    }
  }

  return matchArray;
}

int sumMatchValues(struct String matchArray) {
  struct IntArray asciiValueArray = {.size = 0, .content = NULL};
  int sumValue = 0;
  int lowerCaseAscii = 96;
  int upperCaseAscii = 38;
  for (int i = 0; i < matchArray.size; i++) {
    int currentValue = matchArray.content[i];
    int asciiValue = (int)currentValue;

    // printf("%c", currentValue);
    // printf("%s", "\n");
    // printf("%d", asciiValue);
    // printf("%s", "\n\n");

    if (asciiValue < 97 && currentValue) {
      asciiValueArray.size = asciiValueArray.size + 1;

      asciiValueArray.content =
          realloc(asciiValueArray.content, asciiValueArray.size * sizeof(int));

      int priorityValue = asciiValue - upperCaseAscii;

      asciiValueArray.content[asciiValueArray.size - 1] = priorityValue;

      continue;
    }

    if (asciiValue >= 97 && currentValue) {
      asciiValueArray.size = asciiValueArray.size + 1;

      asciiValueArray.content =
          realloc(asciiValueArray.content, asciiValueArray.size * sizeof(int));

      int priorityValue = asciiValue - lowerCaseAscii;

      // printf("%d", priorityValue);

      asciiValueArray.content[asciiValueArray.size - 1] = priorityValue;

      continue;
    }
  }

  for (int i = 0; i < asciiValueArray.size; i++) {
    int currentValue = asciiValueArray.content[i];

    // printf("%d", currentValue);
    // printf("%s", "\n");
    // printf("%d", sumValue);
    // printf("%s", "\n\n");

    sumValue = sumValue + currentValue;
  }

  free(asciiValueArray.content);
  asciiValueArray.content = NULL;

  return sumValue;
}

int main() {
  FILE *file = NULL;
  struct String fileData = readInputText(file);
  struct String matchArray = loopRuckSacks(fileData);
  int sumValue = sumMatchValues(matchArray);

  printf("%d", sumValue);

  return 0;
}
