#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i;
  int j = atoi(argv[1]);
  char ch = 'f';
  char ch2 = ' ';
  for(i = 0; i < j; i++){
    ch = rand()%128;
    write(1,&ch,1);
    write(1,&ch2,1);
  }
  /*
  char* ch = (char*)malloc(sizeof(char));
  while(read(0,ch,1)){
    memfrob(ch,1);
    write(1,ch,1);
  }
  free(ch);
  */
}
