#include <stdio.h>
#include <stdlib.h>

int frobcmp(char const* s1, char const* s2){
  const char* c1 = s1;
  const char* c2 = s2;
  int i = 0;
  while(free){
    memfrob(c1+i, sizeof(char));
    memfrob(c2+i, sizeof(char));
    char first = c1[i];
    char second = c2[i];
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
  char** input = (char**)malloc(1*sizeof(char*));
  if(!input){
    fprintf(stderr,"%s\n","Memory Allocation Error");
    return 1;
  }
  int numWords = 0;
  input[numWords] = (char*)malloc(1*sizeof(char));
  if(!input[numWords]){
    fprintf(stderr,"%s\n","Memory Allocation Error");
    return 1;
  }
  int numChars = 0;
  int maxChars = 0;
  int ch;
  while((ch = fgetc(stdin)) != EOF){
    input[numWords][numChars] = ch;
    if(input[numWords][numChars] == ' '){
      numChars++;
      if(numChars > maxChars){
	maxChars++;
	int i = 0;
	for(i = 0; i < numWords; i++){
	  char* temp = (char*)realloc(input[i],maxChars*sizeof(char));
	  if(temp){
	    input[i] = temp;
	  }
	  else{
	    fprintf(stderr,"%s\n","Memory Allocation Error");
	    return 1;
	  }
	}
      }
      numChars = 0;
      numWords++;
      char** temp = (char**)realloc(input, (numWords+1)*sizeof(char*));
      if(temp){
	input = temp;
      }
      else{
	fprintf(stderr,"%s\n","Memory Allocation Error");
	return 1;
      }
      input[numWords] = (char*)malloc(maxChars*sizeof(char));
      if(!input[numWords]){
	fprintf(stderr,"%s\n","Memory Allocation Error");
	return 1;
      }
      continue;
    }
    numChars++;
    if(numChars > maxChars){
      maxChars++;
      int i;
      for(i = 0; i < numWords; i++){
	char* temp = (char*)realloc(input[i],maxChars*sizeof(char));
	if(temp){
	  input[i] = temp;
	}
	else{
	  fprintf(stderr,"%s\n","Memory Allocation Error");
	  return 1;
	}
      }
    }
    char* temp = (char*)realloc(input[numWords],(numChars+1)*sizeof(char));
    if (temp){
      input[numWords] = temp;
    }
    else{
      fprintf(stderr,"%s\n","Memory Allocation Error");
      return 1;
    }
  }
  if(numWords == 0 && numChars == 0){
    free(input[numWords]);
    free(input);
    return 0;
  }
  if(input[numWords][numChars] != ' '){
    if(numChars == 0){
      free(input[numWords]);
      numWords--;
    }
    else{
      input[numWords][numChars] = ' ';
      numChars++;
      if(numChars > maxChars){
	maxChars++;
	int i;
	for(i = 0; i < numWords; i++){
	  char* temp = (char*)realloc(input[i],maxChars*sizeof(char));
	  if(temp){
	    input[i] = temp;
	  }
	  else{
	    fprintf(stderr,"%s\n","Memory Allocation Error");
	    return 1;
	  }
	}
      }
    }
  }
  qsort(input, numWords+1, sizeof(*input), cmpConverter);
  int i;
  for(i = 0; i <= numWords; i++){
    int j;
    for(j = 0; j < maxChars; j++){
      fprintf(stdout,"%c",input[i][j]);
      if(input[i][j] == ' '){
	break;
      }
    }
  }
  fprintf(stdout,"%d",count);
  for(i = 0; i <= numWords; i++){
    free(input[i]);
  }
  free(input);
  return 0;
}
