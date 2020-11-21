#include <stdio.h>
#include <math.h>

double f(int x){
  double ans = 0;
  ans = (x*x*x*x) - 2*(x*x*x) + (x*x) - 3*x + 1;
  return ans;
}

int main(){
  int n;
  printf("台形法を行います.\n積分区間は何等分しますか\n");
  scanf("%d", &n);

  double y[n+1];

  for(int i = 0; i <= n; i++){
    int t=0;
    y[t] = f(i);
    t++;
  }

  double s_1 = 0;
  s_1 = y[0] + y[n];
  
  double s_2 = 0;
  for(int t = 1; t < n; t++){
    s_2 += y[t];
  }



  double s = 0;
  s = (3 / n * s_1 / 2) + s_2;

  printf("台形法での答えは%fです.\n", s);

return 0;
}

