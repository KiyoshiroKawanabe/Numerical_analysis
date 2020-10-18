#include <stdio.h>
#include <math.h>

double get_x1( double x2, double x3 )
{
    return( (10.0 - x2 - x3) / 5.0 );
}

double get_x2( double x1, double x3 )
{
    return( (12 - x1 - x3) / 4.0 );
}

double get_x3( double x1, double x2 )
{
    return( (13.0 - 2.0 * x1 - x2) / 3.0 );
}

int main()
{
    double x1, x2, x3;
    int i;
    double A, B, C;

    x1 = x2 = x3 = 1.0; //最初適当な値
    
    for( i=0; i<100; i++ )
    {
        x1 = get_x1( x2, x3 );
        x2 = get_x2( x1, x3 );
        x3 = get_x3( x1, x2 );
   
        A = fabs(x1 - get_x1( x2, x3 ));//それぞれの差を絶対値で出す。
        B = fabs(x2 - get_x2( x1, x3 ));
        C = fabs(x3 - get_x3( x1, x2 ));

         if (i < 9){        //場合分けで出力の形を整える。小数点以下10桁表示。
            printf( "[i= %d] x1 = %11.10f, x2 = %11.10f, x3 = %11.10f\n",i+1, x1, x2, x3 );
         } else{
            printf( "[i=%d] x1 = %11.10f, x2 = %11.10f, x3 = %11.10f\n",i+1, x1, x2, x3 );
         }

         if (A < 0.0000001 && B < 0.0000001 && C < 0.0000001)//計算した差が0.0000001未満のときループを終わらせる。
           break;
         

    }

    
    return 0;
}

