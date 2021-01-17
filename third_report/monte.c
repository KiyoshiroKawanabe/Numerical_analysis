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

  srand(time(NULL));

  for(i=0; i<max ; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    
    if((x*x + y*y) < 1)
      count++;
  }

  PI = (double)count / max * 4;
  printf("円周率は%f\n", PI);

  return 0;
}
