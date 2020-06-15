#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pos(char *c,char e){
    int l=-1;
    char e1;
    if(e >= 'a' && e<= 'z') e1 = e - 32;
    else e1 = e +32;
    for(int i = 0;i<strlen(c);i++) if(c[i]==e || c[i]==e1) l = i;
    return l+1;
}
int main()
{
    char *c,e,c1[20];
    c = (char *)malloc(20);
    fgets(c,20,stdin);
    scanf("%c",&e);
    fgets(c1,20,stdin);
    printf("%d\n",pos(c,e));
    fgets(c1,20,stdin);
    puts(c1);
    free(c);
    free(c1);

}
