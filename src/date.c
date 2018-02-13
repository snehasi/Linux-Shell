#include <time.h>
#include <stdio.h>
int main(int argc, char **argv){
    time_t tim = time(NULL);
    struct tm *point = localtime(&tim);
    char date[1024];
    strftime(date, sizeof(date), "%c", point);
    printf("%s\n", date);

}
