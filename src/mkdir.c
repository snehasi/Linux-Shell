#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
  char *option =argv[1];
  char *xx=argv[2];
  if(strcmp(option,"-v")==0){
    xx[strlen(xx)-1]='\0';
    mode_t mod = 0777;
    int mk = mkdir(xx,mod);
    printf("%s\n",xx);
    if (mk == -1) {
        printf("%s\n","ERROR: Name of directory not specified.");
        exit(0);
    }
    else{
      exit(0);
    }


  }
  else{
    option[strlen(option)-1]='\0';
    mode_t mod = 0777;
    int mk = mkdir(option,mod);
    if (mk == -1) {
        printf("%s\n","ERROR: Name of directory not specified.");
        exit(0);
    }
    else{
      exit(0);
    }
  }
  return 0;

}
