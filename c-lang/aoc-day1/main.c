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
  int currentCalory = 0;
  char* calory = NULL;
  int calorySize = 0;
  int* allCalories = NULL;
  int allCaloriesSize = 0;

  struct CalculateElfCaloriesReturn elfCaloriesReturn;

  for (int i = 0; i < buffSize; i++) {
    char currentChar = buff[i];
    
    if (currentChar == '\n' && buff[i + 1] == '\n') {
      int caloryConverted = atoi(calory);
      currentCalory = currentCalory + caloryConverted;

      allCaloriesSize = allCaloriesSize + 1;
      allCalories = realloc(allCalories, allCaloriesSize * sizeof(int));
      allCalories[allCaloriesSize - 1] = currentCalory;

      currentCalory = 0;
      calory = "";
      calorySize = 0;
      i = i + 2;
      continue;
    }

    if (currentChar == '\n') {
      int caloryConverted = atoi(calory);

      currentCalory = currentCalory + caloryConverted;

      calory = "";
      calorySize = 0;
      continue;
    }

    calorySize = calorySize + 1;
    calory = realloc(calory, calorySize * sizeof(int));
    calory[calorySize - 1] = currentChar; 
  }
  
  elfCaloriesReturn.allCalories = allCalories;
  elfCaloriesReturn.allCaloriesSize = allCaloriesSize;

  return elfCaloriesReturn;
}

int getTheHighestCalories(struct CalculateElfCaloriesReturn elfCaloriesReturn) {
  int highestCalories = 0;
  int highestCaloriesIndex = 0;
  int* topThreeCalories = malloc(3 * sizeof(int));
  int topThreeCaloriesSize = 0;

  int topThreeSum = 0;

  int j = 0;

  while(j < elfCaloriesReturn.allCaloriesSize) {
    printf("%d", elfCaloriesReturn.allCalories[j]);
    printf("%s", "\n\n");
    if (topThreeCaloriesSize == 3) {
      break;
    }

    if (topThreeCaloriesSize < 3 && j == elfCaloriesReturn.allCaloriesSize - 1) {
      topThreeCalories[topThreeCaloriesSize] = elfCaloriesReturn.allCalories[highestCaloriesIndex]; 
      elfCaloriesReturn.allCalories[highestCaloriesIndex] = 0;
      highestCalories = 0;
      highestCaloriesIndex = 0;
      topThreeCaloriesSize = topThreeCaloriesSize + 1;
      j = 0;
      continue;
    }
    
    if (highestCalories < elfCaloriesReturn.allCalories[j]) {
      highestCalories = elfCaloriesReturn.allCalories[j];
      highestCaloriesIndex = j;
      j++;
    } else {
      j++;
    }
  }

  for (int k = 0; k < topThreeCaloriesSize; k++) {
    topThreeSum = topThreeCalories[k] + topThreeSum;
  }

  free(topThreeCalories);

  return topThreeSum;
}

int main() {
  FILE* fp = NULL;
  char* buff = NULL;

  struct ReadDataFromInput readData = readDataFromInput(fp, buff);

  struct CalculateElfCaloriesReturn elfCaloriesReturn = calculateElfCalories(readData.buff, readData.buffSize);  

  int highestCalories = getTheHighestCalories(elfCaloriesReturn);

  printf("%d", highestCalories);

  return 0;
}