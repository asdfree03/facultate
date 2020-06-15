#include <stdio.h>
#include <stdlib.h>

int divizori(int n){
    int suma= 0;
for(int i = 1;i<n;i++) if(n % i ==0) suma+=i;
if(suma == n) return 0;
if(suma >n) return 1;
if(suma <n) return -1;
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    if(x>=y) for(int i = y;i<=x;i++){
        switch(divizori(i)){
        case 0: printf("%d perfect",i); break;
        case 1: printf("%d abundent",i); break;
        case -1: printf("%d deficient",i); break;
        }
    printf("\n");
    }
    else for(int i = x;i<=y;i++){
        switch(divizori(i)){
        case 0: printf("%d perfect",i); break;
        case 1: printf("%d abundent",i); break;
        case -1: printf("%d deficient",i); break;
        }
        printf("\n");
    }
}
