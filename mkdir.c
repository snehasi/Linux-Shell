#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
    char *xx=argv[1];
    //printf("%s\n","hi");
    //int x=strcmp(argv[1],NULL);
    xx[strlen(xx)-1]='\0';
    //printf("%d\n",x);
    mode_t mod = 0777;
    int mk = mkdir(xx,mod);
    if (mk == -1) {
        printf("%s\n","ERROR: Name of directory not specified.");
        exit(0);
    }
    else{
      exit(0);
    }
    return 0;
}
