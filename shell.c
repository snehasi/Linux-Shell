//SNEHA SINHA, 2016098
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char **argv) {
  ///∗ main loop ∗/
  int num=100;
  char *array[200];
  while (num>50) {
  ///∗ print prompt string ∗/ ...
    printf("%s\n","ush" );
  ///∗ read argv[0] from stdin ∗/ ...
    if(fgets(argv[0],sizeof(argv[0]),stdin)==NULL){
      break;
    }

  ///∗ parse argv[0] −− exit if quit ∗/ ...
  //removed newline character
    if(argv[0][strlen(argv[0])-1] == '\n') {
      argv[0][strlen(argv[0])-1] = '\0';
    }
    if(strcmp(argv[0],"exit")==0){
      exit(0);
    } //exit

    if(strcmp(argv[0],"pwd")==0){
      char f[3000];
      getcwd(f, sizeof(f));
      //printf("Current directory is: %s\n");
    } //pwd

    if(strcmp(argv[0],"cd")==0){
      printf(argv[1]);
      char gdir[100];
      strcpy(gdir, "/");
      strcat(gdir, argv[1]);
      chdir(gdir);

      //chdir(argv[1]);

      printf("hey");
      continue;
    }

    char *fp =strtok(argv[0]," ");
    int j=0;
    while(fp!=NULL){
      array[j]=fp;
      j++;
      fp=strtok(NULL," ");
    }
    array[j]="\0";

    //printf("The argv[0] is %s\n",array[0]);

    if (fork() == 0) {
  ///∗ this is the child ∗/ ...
  ///∗ use exec to run the argv[0] ∗/ ...
        execvp(argv[0],argv);
        printf("Command not found \n");
        exit(0);
  ///∗ exit child ∗/
    } else {
  ///∗ this is the parent ∗/ ...
        wait ( NULL );

        }
      }
  }
