#include <assert.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/* definitions */
#define start "#include<stdio.h>\nint main(void){\n"
#define end "\nreturn 0;\n}\n"
#define persistent "./tmp/mainPer.c"
#define null NULL
char *New(ssize_t size) { return (char *)malloc(sizeof(char) * size); }

int getlines(char *ptr, FILE *fp) {
  int nl = 0;
  while (fread(ptr, sizeof(char), 1, fp) != 0) {
    if (*ptr == '\n') {
      nl++;
    }
  };
  assert(nl > 0);
  return nl;
}

ssize_t getbytes(FILE *fp) {
  fseek(fp, 0, SEEK_END);
  assert(ftell(fp) > 0);
  return ftell(fp);
}

void delbottomlines(FILE *fp, int lines) {
  int i = -1, count = 0;
  char *ptr = New(1);
  getbytes(fp);
  lines++;
  fseek(fp, i, SEEK_END);
  while (1) {
    fread(ptr, 1, 1, fp);
    fseek(fp, -1, SEEK_CUR);
    if (*ptr == '\n')
      count++;
    if (count == lines)
      break;
    fwrite(" ", 1, 1, fp);
    fseek(fp, -2, SEEK_CUR);
    i--;
  }
}

int compile() {
  pid_t mainpid = getpid();
  int status = 0;
  fork();
  if (mainpid != getpid()) {
    status = execlp("runcc", "runcc", "tempnew.c", NULL);
    exit(status);
  }
  return status;
}

int execute(char *buffer, FILE *fp) {
  assert(buffer != null);
  fwrite(buffer, 1, strlen(buffer), fp); // this doesnt work when in a loop?
  fwrite((char *)end, 1, strlen((char *)end), fp);

  int status = compile();
  printf("staus %d", status);
  // assert(status < );
  return 0;
}

int main() {
  FILE *fp = fopen("tempnew.c", "w+");
  assert(fp != NULL);

  // write start into file

  char *buffer = New(100);
  int c, i;
  while (1) {
    fseek(fp, 0, SEEK_SET);
    ssize_t stat = ftell(fp);
    fwrite((char *)start, 1, strlen((char *)start), fp);

    //  suddenly code breaks with a loop
    i = 0;
    printf(">> ");
    // read characters
    while ((c = getchar())) {
      if (c == '\n')
        break;
      if (i < 100)
        buffer[i] = c;
      i++;
    }
    // maybe repassing in the file pointer again?
    execute(buffer, fp);
  }
  printf("buffer : %s\n", buffer);
  fclose(fp);
  exit(0);
}
