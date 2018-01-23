//SNEHA SINHA, 2016098
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp,strcat
#include <unistd.h> //getcwd


void printhistory(char *history[],int count);

int main(int argc, char **argv) {
  ///∗ main loop ∗/
  int num=100;
  char *array[200];
  char *history[100];
  int count=0;
  char command[10000];
  while (num>50) {
  ///∗ print prompt string ∗/ ...
    printf("%s","si-shell $ " );
  ///∗ read command from stdin ∗/ ...
    if(fgets(command,sizeof(command),stdin)==NULL){
      break;
    }
  ///∗ parse command −− exit if quit ∗/ ...
  //removed newline character
  //parsing
    char* token;
    token = strtok(command, " ");
    int l=0;
    while (token != NULL) {
        argv[l]=token;
        token = strtok(NULL, " ");
        //printf(argv[l]);
        //printf("xxxx");
        l++;
    }
    argv[l]=NULL;

    if(command[strlen(command)-1] == '\n') {
      command[strlen(command)-1] = '\0';
    }

    history[count]=strdup(command);
    count++;


    if(strcmp(command,"exit")==0){
      exit(0);
    } //exit

    if(strcmp(command,"pwd")==0){
      char f[3000];
      char *xx=getcwd(f, sizeof(f));
      printf("%s\n",xx);


      //printf("Current directory is: %s\n");
    } //pwd

    if(strcmp(command,"cd")==0){
      //printf(argv[1]);
      if(argv[1]==NULL){
        char *dest = getenv("HOME");
        chdir(dest);
        setenv("PWD",dest,1);
        continue;
      }
      else{
        char f[3000];
        char *xx=getcwd(f, sizeof(f));
        char *des = strcat(xx,"/");
        char *dest=strcat(des,argv[1]);
        char *p;
        p = strchr (dest,'\n');
        dest[strlen(dest)-1]='\0';
        chdir(dest);
        setenv("PWD",dest,1);
        continue;
      }

    }//cd

    if(strcmp(command,"echo")==0){
      char *stringg = argv[1];
      printf("%s\n",stringg);
      //printf(sizeof(argv));
      //printf(argv[1]);
    }
    //printf(command);
    if(strcmp(command,"history")==0){
      //printf("hey");
      printhistory(history,count);
    }
    int pid=fork();
    //fork();
    //printf(pid);

    if (pid == 0) {
  ///∗ this is the child ∗/ ...
  ///∗ use exec to run the command ∗/ ...
        //printf("xxx");
        //printf(command);
        if(strcmp(command,"cat")==0){
          printf("%s\n",argv[1]);
          printf("%s\n","testing");
          char *p[3];
          p[0]="./cat";
          p[1]=argv[1];
          p[2]=NULL;
          execv(p[0], p);
        }

        if(strcmp(command,"ls")==0){
          //printf("%d\n",x);
          char f[3000];
          char *xx=getcwd(f, sizeof(f));
          //char *xx=getenv("PWD");
          //printf("%s","ggggg");
          //printf("%s\n",xx);
          //char *const p = {"./ls",xx,NULL};
          char *p[3];
          p[0]="/Users/snehasi/Desktop/2016098/ls";
          p[1]=xx;
          p[2]=NULL;
          execv(p[0], p);
        }



        // execvp(command,argv);
        // printf("Command not found \n");
        exit(0);

  ///∗ exit child ∗/
    } else {
  ///∗ this is the parent ∗/ ...
        //printf("yyyyy");
        wait ( NULL );


        }
      }
      return 0;
  }

void printhistory(char *history[],int count){
  int i=0;
  while(history[i]!=NULL && i<count){
    printf("%s\n",history[i]);
    i=i+1;
  }
}
