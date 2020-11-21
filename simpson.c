#include <stdio.h>
#include <math.h>

double f(int x){
  double fx = 0;
  fx = x*x*x*x - 2*x*x*x + x*x - 3*x + 1;
  return fx;
}

int n, i;
double delta = 0;
double s_1 = 0, s_2 = 0, s = 0;
double y[1000];

int main(){
  printf("台形公式を行います\n積分区間は何等分しますか？\n");
  scanf("%d", &n);

  delta = 3 / n;

  for(i = 0; i <= n; i++){
    y[i] = f(i);
  }

  s_1 = (y[0] + y[n]) / 2;

  for(int t = 1; t < n; t++){
    s_2 = s_2 + y[t];
  }

  s = delta * (s_1 + s_2);

  printf("答えは%lfです\n", s);

  return 0;
}

