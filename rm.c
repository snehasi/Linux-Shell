#include <ftw.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[]){
    char *xx=argv[1];
    xx[strlen(xx)-1]='\0';
    remove(xx);
    return 0;

}
