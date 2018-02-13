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

    //printf("%s\n", command);
  ///∗ parse command −− exit if quit ∗/ ...
  //removed newline character
  //parsing
    char* token;
    token = strtok(command, " ");
    int l=0;
    while (token != NULL) {
        argv[l]=token;
        token = strtok(NULL, " ");
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
    } //pwd

    if(strcmp(command,"cd")==0){
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
        dest[strlen(dest)-1]='\0';
        chdir(dest);
        if(chdir(dest)==0){
          setenv("PWD",dest,1);
          continue;
        }
        else{
          printf("%s\n","No such directory exists.");
        }

      }

    }//cd

    if(strcmp(command,"echo")==0){
      char *stringg = argv[1];

      if(strcmp(argv[1],"-n")==0){
        int i=2;
        while(argv[i]!=NULL){
          if(i==2){
            printf("%s",argv[i]);
          }
          else{
            printf("%s"," ");
            printf("%s",argv[i]);
          }
          i++;
        }
      }
      else{
        int i=1;
        while(argv[i]!=NULL){
          if(i==1){
            printf("%s",argv[i]);
          }
          else{
            printf("%s"," ");
            printf("%s",argv[i]);
          }
          i++;
        }
      }
    }

    if(strcmp(command,"history")==0){
      printhistory(history,count);
    }
    int id=fork();

    if (id == 0) {
  ///∗ this is the child ∗/ ...
  ///∗ use exec to run the command ∗/ ...
        if(strcmp(command,"cat")==0){
          char *p[4];
          p[0]="/Users/snehasi/Desktop/2016098/src/cat";
          p[1]=argv[1]; //option
          p[2]=argv[2]; //filename
          p[3]=NULL;
          execv(p[0], p);
        }

        if(strcmp(command,"ls")==0){
          char f[3000];
          char *xx=getcwd(f, sizeof(f));
          char *p[4];
          p[0]="/Users/snehasi/Desktop/2016098/src/ls";
          p[1]=xx;
          p[2]=argv[1];
          p[3]=NULL;
          execv(p[0], p);
        }

        if(strcmp(command,"date")==0){
          char *p[3];
          p[0]="/Users/snehasi/Desktop/2016098/src/date";
          p[1]=".";
          p[2]=NULL;
          execv(p[0], p);

        }


        if(strcmp(command,"mkdir")==0){
          char *p[4];
          p[0]="/Users/snehasi/Desktop/2016098/src/mkdir";
          p[1]=argv[1]; //option
          p[2]=argv[2]; //directory
          p[3]=NULL;
          execv(p[0], p);

        }

        if(strcmp(command,"rm")==0){
          char *p[4];
          p[0]="/Users/snehasi/Desktop/2016098/src/rm";
          p[1]=argv[1]; //command
          p[2]=argv[2]; //option
          p[3]=argv[3]; //filename
          execv(p[0], p);

        }



        // execvp(command,argv);
        if(strcmp(command,"pwd")!=0 && strcmp(command,"echo")!=0  && strcmp(command,"history")!=0 && strcmp(command,"cd")!=0){
          printf("ERROR: Command not found in shell. \n");

        }

        exit(0);

  ///∗ exit child ∗/
    } else {
  ///∗ this is the parent ∗/ ...
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
