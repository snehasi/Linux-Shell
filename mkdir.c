#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
    char *xx=argv[1];
    //printf("%s",xx);
    //int x=strcmp(xx,"test");
    xx[strlen(xx)-1]='\0';
    //printf("%d\n",x);
    mode_t mod = 0777;
    if (mkdir(xx,mod) == -1) {
        perror(argv[0]);
        exit(0);
    }
    return 0;
}
