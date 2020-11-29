#include <stdio.h>
#include <ctype.h>

int main(){
  FILE *rf;
  char str, mid, let[27]={'a'}, LET[27]={'A'}, alpha='a', ALPHA='A';
  int math[27] = {0}, i, tmp, x, M=0;
  double trend = 0;

//letは文字letterの略。大文字小文字一つずつ入れとります。
  for(int i = 0; i < 26; i++){
    let[i] = alpha;
    LET[i] = ALPHA;
    alpha++;
    ALPHA++;
  }
  let[26] = ' ';//最後の27番目はスペース
  LET[26] = ' ';

//ファイルオープン
  rf = fopen("file10.txt", "r");
//開かなかった時エラー表示
  if(rf == NULL){
    printf("ファイルオープンエラー\n");
    return -1;
  }
//総文字数Mを数えます
  while((str = fgetc(rf)) != EOF){
    M++;
  }
  printf("\n文字総数 : %d\n", M);
  rewind(rf);
//アルファベットの数を数えています。math配列は数を入れてます。
  while((str = fgetc(rf)) != EOF){
    if(isalpha(str) || str == ' '){
      for(int i = 0; i < 27; i++){
        if(str == let[i] || str == LET[i]){
          math[i]++;
        }
      }
    }
  }
//多い順に並べ替えます
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
  printf("\n<<使用率ランキング>>\n");

  printf("----------------------------------------\n");

  
  for(i = 0,x = 1; i < 27,x < 28; i++,x++){
    trend = (double)math[i] / M * 100;
    printf("%4d位 [%C]:%7d    使用率 %6.3lf％\n", x, let[i], math[i], trend);
  }

  fclose(rf);
  return 0;
}

