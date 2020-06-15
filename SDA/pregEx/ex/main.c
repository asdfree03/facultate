#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double k; double x,y,z;
int n;
double cordic(double teta){
    k=1;
    for(int i=0;i<n;i++){
    k = k* pow(1+pow(2,-2*i),0.5);
    x = 1/k;
    y = 0;
    z = teta;
            double auxx,auxy;
            auxx = x;
            auxy = y;
        if(z>=0){
            x = auxx-pow(2,-i)*auxy;
            y=auxy+pow(2,-i)*auxx;
            z = z -atan(pow(2,-i));
        }
        else{
            x = auxx+pow(2,-i)*auxy;
            y=auxy-pow(2,-i)*auxx;
            z = z +atan(pow(2,-i));
        }
    }
    return x;
}
int main()
{
    n = 15;
    printf("%.8f\n",(cordic(M_PI/6)));
    printf("%.8f\n",cos(M_PI/6));
   // printf("%.8f\n\n",cordic(M_PI/6)-cos(M_PI/6));
}
