#include <stdio.h>
#include <math.h>

double f(int x){
  double fx = 0;
  fx = x*x*x*x - 2*x*x*x + x*x - 3*x + 1;
  return fx;
}

int n, i;
double delta = 0;
double s_1 = 0, s_2 = 0, s_3 = 0, s = 0;
double y[1000];

int main(){
  printf("シンプソン法を行います\n積分区間は何等分しますか？\n");
  scanf("%d", &n);

  delta = 3 / n;

  for(i = 0; i <= n; i++){
    y[i] = f(i);
  }

  s_1 = (y[0] + y[n]);

  for(int t=1; t<n; t=t+1){
    s_2 = s_2 + y[t];
  }

  for(int e=2; e<n; e=e+2){
    s_3 = s_3 + y[e];
  }

  s = delta / 3 * (s_1 + 4 * s_2 + 2 * s_3);

  printf("答えは%lfです\n", s);

  return 0;
}

