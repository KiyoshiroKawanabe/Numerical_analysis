#include <stdio.h>
#include <ctype.h>

int main(){
  FILE *rf, *wf;
  char str;

  rf = fopen("archive.txt", "r");
  wf = fopen("file10.txt","w");

  if(rf == NULL || wf == NULL){
    printf("ファイルオープンエラー\n");
    return -1;
  }

  while((str = fgetc(rf)) != EOF){
    if(isalpha(str)){
      putchar(str);
      fputc(str, wf);
    }else if(str == ' ' || str == '\n'){
      putchar(str);
      fputc(str, wf);
    }else{
      str = ' ';
      putchar(str);
      fputc(str, wf);
    }

  }

  fclose(rf);
  fclose(wf);

  return 0;
}
