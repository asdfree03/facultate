#include <stdio.h>
#include <stdlib.h>
int a[10]; int pos[10];
void init(int n){
    for(int i = 0;i<n;i++) pos[i] = i+1;
}
void afisare(int n){
    for(int i = 0;i<n;i++) printf("%d",a[i]);
    printf("\n");
}
int solutie(int k,int n){
    if(n == k) return 1;
    return 0;
}
int valid(int x,int k){
    for(int i = 0;i<k;i++) if(a[i]==x) return 0;
    return 1;
}
int back(int k,int n){
    if(solutie(n,k)) afisare(n);
    else{
        for(int i = 0;i<n;i++)
        if(valid(pos[i],k)){
                a[k] = pos[i];
                back(k+1,n);
        }
    }
}
int main()
{
    int n = 3;
    init(n);
    back(0,n);
}
