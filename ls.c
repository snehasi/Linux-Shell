//ls
#include <dirent.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
  DIR *directory;
  struct dirent *dir;
  //argv has st array containing store
  //printf(argv[0]);
  //char f[3000];
  //char *xx=getcwd(f, sizeof(f));
  //printf("%s\n","fml");
  //printf("%s\n",argv[1]);
  char *ss=argv[1];
  directory = opendir(ss);
  if (directory!=NULL)
  {
    //printf("ccc");

      while ((dir = readdir(directory)) != NULL)
      {
          printf("%s\n", dir->d_name);
      }
      closedir(directory);
  }
  else{
    printf("%s\n","Directory not found.");
  }

  return 1;
}
