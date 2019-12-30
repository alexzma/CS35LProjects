#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

static int ignore_case = 0;

int frobcmp(char const* s1, char const* s2){
  const char* c1 = s1;
  const char* c2 = s2;
  int i = 0;
  while(free){
    memfrob(c1+i, sizeof(char));
    memfrob(c2+i, sizeof(char));
    char first = c1[i];
    char second = c2[i];
    if(ignore_case){
      if(first == EOF || first >= 0 && first <= UCHAR_MAX){
	first = toupper(first);
      }
      if(second == EOF || second >= 0 && second <= UCHAR_MAX){
	second = toupper(second);
      }
    }
    if(first != second){
      int temp = first - second;
      memfrob(c1+i, sizeof(char));
      memfrob(c2+i, sizeof(char));
      return temp;
    }
    memfrob(c1+i, sizeof(char));
    memfrob(c2+i, sizeof(char));
    if(first == ' '){
      if (second == ' '){
	return 0;
      }
      return -1;
    }
    if (second == ' '){
      return 1;
    }
    i++;
  }
  return 0;
}

int cmpConverter(const void* s1, const void* s2){
  const char* c1 = *(const char**)s1;
  const char* c2 = *(const char**)s2;
  return frobcmp(c1, c2);
}

int main(int argc, const char * argv[]) {
  int iterator;
  for(iterator = 0; iterator < argc; iterator++){
    int i;
    for(i = 0; i < 3; i++){
      if(i == 0 && argv[iterator][i] != '-'){
	break;
      }
      if(i == 1 && argv[iterator][i] != 'f'){
	break;
      }
      if(i == 2 && argv[iterator][i] == '\0'){
	ignore_case = 1;
      }
    }
    if(ignore_case)
      break;
  }
  char** input = (char**)malloc(1*sizeof(char*));
  if(!input){
    fprintf(stderr,"%s\n","Memory Allocation Error");
    return 1;
  }
  int numWords = 0;
  struct stat* buf = (struct stat*)malloc(sizeof(struct stat));
  int numChars = 0;
  int maxChars;
  char* charArray;
  if(fstat(0,buf) >= 0 && S_ISREG(buf->st_mode)){
    maxChars = buf->st_size;
  }
  else{
    maxChars = 0;
  }
  charArray = (char*)calloc(maxChars+1, sizeof(char));
  free(buf);
  if(!charArray){
    fprintf(stderr,"%s\n","Memory Allocation Error");
    free(input);
    return 1;
  }
  input[0] = &charArray[0];
  char* ch = (char*)malloc(sizeof(char));
  if(!ch){
    fprintf(stderr,"%s\n","Memory Allocation Error");
    free(input);
    free(charArray);
    return 1;
  }
  int reserved = -1;
  if(read(0,charArray,maxChars)){
    for(numChars = 0; numChars < maxChars; numChars++){
      if(charArray[numChars] == ' '){
	numChars++;
	numWords++;
	char** temp = (char**)realloc(input, (numWords+1)*sizeof(char*));
	if(temp){
	  input = temp;
	}
	else{
	  fprintf(stderr,"%s\n","Memory Allocation Error");
	  free(input);
	  free(charArray);
	  free(ch);
	  return 1;
	}
	input[numWords] = &charArray[numChars];
      }
    }
    if(charArray[numChars] != ' ' && charArray[numChars] != input[numWords][0])
    {
      charArray[numChars] = ' ';
      numWords++;
      char** temp = (char**)realloc(input, (numWords+1)*sizeof(char*));
      if(temp){
	input = temp;
      }
      else{
	fprintf(stderr,"%s\n","Memory Allocation Error");
	free(input);
	free(charArray);
	free(ch);
	return 1;
      }
    }
    reserved = numWords;
    input[numWords] = (char*)malloc(1*sizeof(char));
    numChars = 0;
    if(!input[numWords]){
      fprintf(stderr,"%s\n","Memory Allocation Error");
      free(input);
      free(charArray);
      free(ch);
      return 1;
    }
  }
  if(reserved == -1){
    input[numWords] = (char*)malloc(1*sizeof(char));
    if(!input[numWords]){
      fprintf(stderr,"%s\n","Memory Allocation Error");
      free(input);
      free(charArray);
      free(ch);
      return 1;
    }
    reserved = 0;
  }
  while(read(0,ch,1)){//Old Version (Edited)
    input[numWords][numChars] = *ch;
    if(input[numWords][numChars] == ' '){
      numChars = 0;
      numWords++;
      char** temp = (char**)realloc(input, (numWords+1)*sizeof(char*));
      if(temp){
        input = temp;
      }
      else{
        fprintf(stderr,"%s\n","Memory Allocation Error");
	if(reserved != -1){
	  int j;
	  for(j = reserved; j <= numWords; j++){
	    free(input[numWords]);
	  }
	}
	free(ch);
	free(charArray);
	free(input);
        return 1;
      }
      input[numWords] = (char*)malloc(1*sizeof(char));
      if(!input[numWords]){
        fprintf(stderr,"%s\n","Memory Allocation Error");
	if(reserved != -1){
	  int j;   
	  for(j = reserved; j <= numWords; j++){
	    free(input[numWords]);
	  }
	}
	free(ch);
	free(charArray);
	free(input);
        return 1;
      }
      continue;
    }
    numChars++;
    char* temp = (char*)realloc(input[numWords],(numChars+1)*sizeof(char));
    if (temp){
      input[numWords] = temp;
    }
    else{
      fprintf(stderr,"%s\n","Memory Allocation Error");
      if(reserved != -1){
	int j;
	for(j = reserved; j <= numWords; j++){
	  free(input[numWords]);
	}
      }
      free(ch);
      free(charArray);
      free(input);
      return 1;
    }
  }
  if(numWords == 0 && numChars == 0){
    free(charArray);
    free(input);
    free(ch);
    return 0;
  }
  if(reserved == -1 && charArray[numChars] != ' '){
    if(charArray[numChars] == input[numWords][0]){
      numWords--;
    }
    else{
      charArray[numChars] = ' ';
    }
  }
  if(reserved != -1 && input[numWords][numChars] != ' '){
    if(numChars == 0){
      free(input[numWords]);
      numWords--;
    }
    else{
      input[numWords][numChars] = ' ';
    }
  }
  qsort(input, numWords+1, sizeof(*input), cmpConverter);
  int i;
  for(i = 0; i <= numWords; i++){
    int j = 0;
    while(input[i][j] != ' '){
      write(1,input[i]+j,1);
      j++;
    }
    write(1,input[i]+j,1);
  }
  if(reserved != -1){
    int j;
    for(j = reserved; j <= numWords; j++){
      free(input[j]);
    }
  }
  free(ch);
  free(charArray);
  free(input);
  return 0;
}
