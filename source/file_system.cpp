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

char * createPath(FileLocation location) {
  char * uri;

  // Allocate memory for the new string. +1 is for null terminator
  uri = (char*)malloc(strlen(location.path) + strlen(location.fileName) + strlen(location.extension) + 1);

  strcpy(uri, location.path);
  strcat(uri, location.fileName);
  strcat(uri, location.extension);

  return uri;
}

char * readFile(const char *uri) {
  FILE * file = fopen(uri, "r");

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

char * readFileFl(FileLocation location) {
  char * path = createPath(location);
  char * contents = readFile(path);

  free(path);

  return contents;
}
