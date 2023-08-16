#include <stdio.h>
#include <stdlib.h>

struct FileData {
    int size;
    char *content;
};

struct FileData readInputText(FILE *file) {
    struct FileData fileData;
    char *fileContent = NULL;

    file = fopen("./input.txt", "r");

    fseek(file, 0L, SEEK_END); 
    int fileSize = ftell(file);
    rewind(file);
    
    fileContent = malloc(fileSize * sizeof(char));

    fread(fileContent, 0, fileSize, file);

    fileData.size = fileSize;
    fileData.content = fileContent;

    return fileData;
}

int main() {
   FILE *file = NULL;
   struct FileData fileData = readInputText(file);

   return 0; 
}
