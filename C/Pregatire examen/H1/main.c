#include <stdio.h>
#include <stdlib.h>
void afisare(int n){
       for(int j = 31;j>=0;j--) printf("%d",n>>j&1);
        printf("     ");
    char hexaDeciNum[100];
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % 16;
        if(temp < 10){
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else{
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n/16;
    }
    for(int j=i-1; j>=0; j--)
        printf("%c",hexaDeciNum[j]);
        printf("\n");
}
int main()
{   int nr;
    int v[100];
    int n = 0;
    while(1){
        scanf("%d",&nr);
        if(nr!=0) {v[n]=nr;
        n++;}
        else break;
    }
    for(int i = 0;i<n;i++){
        if(v[i] & 1 && (v[i]>>1) & 1 && (v[i]>>2) & 1 && (v[i]>>3) & 1) afisare(v[i]);
        else {
            afisare(v[i]);
            if(v[i] & 1) v[i] = v[i] & ~1;
            else v[i] = v[i]  v[i]^1;
            if((v[i]>>1) & 1) v[i] = (v[i]>>1) & ~1;
            else v[i] = v[i]> ^ v[i]^1;
            v[i] = v[i] ^ 1 | (v[i]>>1) ^1 | (v[i]>>2) ^1 | (v[i]>>3) ^1;
            afisare(v[i]);
        }
    }
}
