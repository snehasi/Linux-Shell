#include <ftw.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, const char *argv[]){
  char *yy=argv[1]; //option
  char *xx=argv[2]; //filename
  if(strcmp(yy,"-d")==0){
    if(xx==NULL){
      printf("%s\n","Filename or directory name not specified.");
    }
    else{
      xx[strlen(xx)-1]='\0';
      remove(xx);
      return 0;
    }
  }
  else if(strcmp(yy,"-v")==0){
    if(xx==NULL){
      printf("%s\n","Filename or directory name not specified. ");
    }
    else{
      xx[strlen(xx)-1]='\0';
      printf("%s\n",xx);
      remove(xx);
      return 0;
    }
  }
  else if(yy==NULL && xx==NULL){
    printf("%s\n","Filename or directory name not specified.");

  }


}
