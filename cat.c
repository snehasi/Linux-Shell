//cat
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
  //printf("%s\n","hey");
  //printf("%s\n", argv[1]);
  //SetHomeDirectory();
  char gg[3000];
  char *xx=getcwd(gg, sizeof(gg));
  chdir(xx);
  // int st = strcmp("writeup.txt",argv[1]);
  // printf("%d",st);
  char *ff =argv[1];
  ff[strlen(ff)-1]='\0';
  //int st = strcmp("writeup.txt",ff);
  //printf("%d",st);
  FILE *file = fopen(ff,"r");
  char *tok;
  if(file!=NULL){
    tok = fgetc(file);
    while (tok != EOF)
    {
        printf ("%c", tok);
        tok = fgetc(file);
    }


    //printf("%s",c);
  }
  else{
    printf("%s","File is not present in the directory.");
  }
  fclose(file);

  return 1;
}
