#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_system.h"

// Returns length in bytes.
long getFileSize(FILE *file) {
  long size;

  fseek(file, 0, SEEK_END); // seek to end of file
  size = ftell(file); // get current file pointer
  rewind(file); // go back to beginning of file

  return size;
}

char * createUri(const char * path, const char * fileName, const char * extension) {
  char * uri;

  // Allocate memory for the new string. +1 is for null terminator
  uri = (char*)malloc(strlen(path) + strlen(fileName) + strlen(extension) + 1);

  strcpy(uri, path);
  strcat(uri, fileName);
  strcat(uri, extension);

  return uri;
}

char * readFile(const char *fileName) {
  FILE * file = fopen(fileName, "r");

  if (!file) {
    fprintf(stderr,"ERROR: couldn't open file\n");
  }

  long size = getFileSize(file);

  // @TODO: How will I remember to free this?
  // https://www.eskimo.com/~scs/cclass/int/sx5.html
  char * buffer = (char*)malloc(size + 1);

  fread(buffer, 1, size, file);

  fclose(file);
  buffer[size] = '\0';

  return buffer;
}
