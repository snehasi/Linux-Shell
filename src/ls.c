//ls
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int lsr(const char *ss);
int lsa(const char *ss);
int main(int argc, char **argv){
  DIR *directory;
  struct dirent *req;
  char *ss=argv[1];
  char *option =argv[2];
  directory = opendir(ss);

  if (directory!=NULL){
      while ((req = readdir(directory)) != NULL){   
          if(option!=NULL){
            option[strlen(option)-1]='\0';
            if(strcmp(option,"-A")==0){
              lsr(ss);
            }
            else if(strcmp(option,"-a")==0){
              lsa(ss);
            }
          }
          else {
            if(strcmp((*req).d_name, ".") == 0 || strcmp((*req).d_name, "..") == 0){
              continue;
            }
            else{
              printf("%s\n", (*req).d_name);
            }
          }
      }
      closedir(directory);
  }
  else{
    printf("%s\n","Directory can not be found.");
  }
  return 1;
}

int lsa(const char *ss){
  DIR *directory;
  struct dirent *req;
  directory = opendir(ss);

  if (directory!=NULL){

      while ((req = readdir(directory)) != NULL){   //printf("%s\n",option);

              printf("%s\n", (*req).d_name);

      }
      closedir(directory);
  }
  else{
    printf("%s\n","Directory can not be found.");
  }
  return 1;
}

int lsr(const char *ss)
{
  DIR *directory;
  struct dirent *req;
  directory = opendir(ss);

  if (directory!=NULL){
      while ((req = readdir(directory)) != NULL){

            if(strcmp((*req).d_name, ".") == 0 || strcmp((*req).d_name, "..") == 0){
              continue;
            }
            else{
              printf("%s\n", (*req).d_name);

            }
      }
      closedir(directory);
  }
  else{
    printf("%s\n","Directory can not be found.");
  }
  return 1;
}
