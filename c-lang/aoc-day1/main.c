#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CalculateElfCaloriesReturn {
  int* allCalories;
  int allCaloriesSize;
};

struct ReadDataFromInput {
  char* buff;
  int buffSize;
};

struct ReadDataFromInput readDataFromInput(FILE* fp, char* buff) {
  struct ReadDataFromInput readData;

  fp = fopen("../../c-lang/aoc-day1/input.txt", "r");

  if (fp == NULL) {
    perror("An error occured reading the file!");
    exit(1);
  }

  int prev = fseek(fp, 0, SEEK_END);

  int size = ftell(fp);

  fseek(fp, prev, SEEK_SET);

  buff = malloc(size * sizeof(char));

  fread(buff, 1, size, fp);

  readData.buff = buff;
  readData.buffSize = size;

  return readData;
};

struct CalculateElfCaloriesReturn calculateElfCalories(char* buff, int buffSize) {
  int* currentCalory = malloc(1 * sizeof(int));
  int* allCalories = NULL;
  int* allCaloriesSize = malloc(1 * sizeof(int));
  *allCaloriesSize = 0;
  *currentCalory = 0;

  struct CalculateElfCaloriesReturn elfCaloriesReturn;

  for (int i = 0; i < buffSize; i++) {
    char currentChar = buff[i];
    
    if (strcmp(&currentChar, "\n") && !strcmp(&buff[i + 1], "\n")) {
      *allCaloriesSize = *allCaloriesSize + 1;
      allCalories = realloc(allCalories, *allCaloriesSize * sizeof(int));
      allCalories[*allCaloriesSize - 1] = *currentCalory;

      currentCalory = 0;
    }

    int calory = currentChar - '0';

    int newCalories = *currentCalory + calory;

    *currentCalory = newCalories;
  }
  
  elfCaloriesReturn.allCalories = allCalories;
  elfCaloriesReturn.allCaloriesSize = *allCaloriesSize;

  return elfCaloriesReturn;
}

int getTheHighestCalories(struct CalculateElfCaloriesReturn elfCaloriesReturn) {
  int* highestCalories = malloc(1 * sizeof(int));

  for (int i = 0; i <= elfCaloriesReturn.allCaloriesSize; i++) {
    if (*highestCalories < elfCaloriesReturn.allCalories[i]) {
      *highestCalories = elfCaloriesReturn.allCalories[i];
    }
  }

  return *highestCalories;
}

int main() {
  FILE* fp = NULL;
  char* buff = NULL;

  struct ReadDataFromInput readData = readDataFromInput(fp, buff);

  struct CalculateElfCaloriesReturn elfCaloriesReturn = calculateElfCalories(readData.buff, readData.buffSize);  

  return 0;
}