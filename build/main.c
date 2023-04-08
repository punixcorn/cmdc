#include <assert.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/* definitions */
#define start "#include<stdio.h>\nint main(void){\n"
#define end "return 0;\n}\n"
#define persistent "./tmp/mainPer.c"
#define npersistent "./tmp/mainNper.c"
/*
 * 1. open the file
 * 2. setup file => { a.put in headers b.put in main }
 * 3. while loop and take in input
 * 4. write into file the input
 * 5. write into file then closing tag
 * 6. compile
 * 7. for later
 * */

int main(void) {
  // open the file as a FILE *
  FILE *fp = fopen(npersistent, "w+"), *nfp;
  assert(fp != NULL);

  // write first line into file
  fwrite((char *)start, sizeof(char), strlen((char *)start), fp);
  assert(write(STDOUT_FILENO, start, strlen((char *)start)) > -1);
  exit(0);
  /* Take input an run */
  char *buffer = (char *)malloc(sizeof(char) * 1024),
       *obuffer = (char *)malloc(sizeof(char));

  return 0;
}
