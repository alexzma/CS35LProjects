#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]){
  if(argc != 3){
    fprintf(stderr, "Invalid number of arguments: %d\n", argc-1);
    return 1;
  }
  char map[128] = {'\0'};
  int i = 0;
  while(argv[1][i] != '\0'){
    if(map[argv[1][i]] != '\0'){
      fprintf(stderr, "No repeat values allowed in original characters.\n");
      return 1;
    }
    map[argv[1][i]] = argv[1][i];
    i++;
  }
  for(i = 0; i < 128; i++){
    map[i] = i;
  }
  i = 0;
  while(argv[1][i] != '\0'){
    if(argv[2][i] == '\0'){
      fprintf(stderr, "Transliteration strings must be of equal length.\n");
      return 1;
    }
    map[argv[1][i]] = argv[2][i];
    i++;
  }
  if(argv[2][i] != '\0'){
    fprintf(stderr, "Transliteration strings must be of equal length.\n");
    return 1;
  }
  int ch;
  while((ch = getchar()) != EOF){
    putchar(map[ch]);
  }
}
