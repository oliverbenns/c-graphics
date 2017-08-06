#include <stdio.h>
#include "file_system.h"
// https://stackoverflow.com/questions/174531/easiest-way-to-get-files-contents-in-c
char * getFile() {
  printf("fleName");
  char * buffer = 0;
  long length;

  FILE * file = fopen (fileName, "rb");

  if (file) {
    fseek (file, 0, SEEK_END);
    length = ftell(f);
    fseek (file, 0, SEEK_SET);
    buffer = malloc(length);
    if (buffer) {
      fread(buffer, 1, length, file);
    }

    fclose (file);
  }

  if (buffer) {
    // start to process your data / extract strings here...
  }

  return buffer;
}
