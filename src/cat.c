//cat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv){
  char gg[3000];
  char *xx=getcwd(gg, sizeof(gg));
  chdir(xx);
  char *option=argv[1]; //option
  char *ff =argv[2]; //filename
  if(option!=NULL){

    if(ff!=NULL){
      if(strcmp(option,"-n")==0){
        ff[strlen(ff)-1]='\0';
        FILE *file = fopen(ff,"r");
        char tok;
        int i=1;
        if(file!=NULL){
          tok = fgetc(file);
          printf("%d",i);
          //i++;
          while (tok != EOF)
          {
              printf ("%c", tok);
              if(tok=='\n'){
                i++;
                printf("%d",i);

              }
              tok = fgetc(file);
          }
        }
        else{
          printf("%s\n","Present directory does not contain the specified file.");
        }
        fclose(file);
      }
    }
    else{  //only filename given
      option[strlen(option)-1]='\0';
      FILE *file = fopen(option,"r");
      char tok;
      if(file!=NULL){
        tok = fgetc(file);
        while (tok != EOF)
        {
            printf ("%c", tok);
            tok = fgetc(file);
        }
      }
      else{
        printf("%s\n","Present directory does not contain the specified file.");
      }
      fclose(file);

    }

  }
  else{  //no second argument, no option , no filename
    printf("%s\n","File name not specified");
  }


  return 1;
}
