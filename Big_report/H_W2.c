#include <stdio.h>
#include <ctype.h>

int main(){
  FILE *wf;
  char str, mid, let[27]={'a'}, LET[27]={'A'}, alpha='a', ALPHA='A';
  int math[27] = {0}, i, tmp;

  for(int i = 0; i < 26; i++){
    let[i] = alpha;
    LET[i] = ALPHA;
    alpha++;
    ALPHA++;
  }
  let[26] = ' ';
  LET[26] = ' ';


  wf = fopen("file10.txt", "r");

  if(wf == NULL){
    printf("ファイルオープンエラー\n");
    return -1;
  }

  while((str = fgetc(wf)) != EOF){
    if(isalpha(str) || str == ' '){
      for(int i = 0; i < 27; i++){
        if(str == let[i] || str == LET[i]){
          math[i]++;
        }
      }
    }
  }

  for(i = 0; i < 27; i++){
    for(int t = i+1; t < 27; t++){
      if(math[i] < math[t]){
        tmp = math[i];
        mid = let[i];
        math[i] = math[t];
        let[i] = let[t];
        math[t] = tmp;
        let[t] = mid;
      }
    }
  }
  printf("大文字,小文字合わせた総数\n");
  for(i = 0; i < 27; i++){
    printf("[%C] : %d\n", let[i], math[i]);
  }

  fclose(wf);
  return 0;
}

