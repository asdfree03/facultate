#include <stdio.h>
#include <stdlib.h>
#define nmax 6
int a[nmax]; int pos[10];
void init(){
    for(int i = 0;i<10;i++) pos[i] = i;
}
void afisare(int n){
    printf("0721");
    for(int i = 0;i<n;i++) printf("%d",a[i]);
    printf("\n");
}
int solutie(int k, int n){
    if(k == n) return 1;
    return 0;
}
int valid(int x,int k,int n){
    int nr_par = 0;
    if(k == n-1){
        for(int i = 0;i<k;i++) if(a[i]%2 == 0) nr_par++;
        if(nr_par %2 == 0){
            if(x % 2 == 0) return 0;
            else return 1;
        }
        else{
            if(x%2 ==0) return 1;
            else return 0;
        }
    }
    return 1;
}
void back(int k,int n){
    if(solutie(k,n)) afisare(n);
    else{
        for(int i = 0;i<10;i++){
            if(valid(pos[i],k,n)){
                a[k] = pos[i];
                back(k+1,n);
            }
        }
    }
}
int main()
{
    int n = nmax;
    init();
    back(0,n);
}
