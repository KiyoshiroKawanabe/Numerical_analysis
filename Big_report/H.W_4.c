#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(){
  FILE *rf;
  char str;
  int M = 0, k=0;

  srand((unsigned int)time(NULL));

  rf = fopen("file10.txt","r");

  if(rf == NULL){
    printf("ファイルオープンエラー\n");
    return -1;
  }

  while((str = fgetc(rf)) != EOF){
      M++;
  }

  printf("総文字数%d\n", M);

  int i = 0, j = 0;

  for(i=0; i<100; i++){
    rewind(rf);
    k = rand()%M;
    while((str = fgetc(rf)) != EOF){
      if(j == k){
          printf("%c", str);
      }
      j++;
    }
    j = 0;
  }
  printf("\n");
  fclose(rf);

  return 0;
}

