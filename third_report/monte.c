#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int max, i;
  printf("ランダムに打つ点の個数を入力してください。");
  scanf("%d", &max);
  printf("%d個の時、\n", max);

  int count = 0;
  double x,y,PI;

  /*乱数の種を初期化*/
  srand(time(NULL));

  /*x,yに0∼1の乱数を代入*/
  for(i=0; i<max ; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;

    /*円内に入っているか判定*/
    if((x-0.5)*(x-0.5) + (y-0.5)*(y-0.5) <= 0.25)
      count++;
  }
  /*円周率PIｎの計算*/
  PI = (double)count / max * 4;
  printf("円周率は%f\n", PI);

  return 0;
}
