#include<stdio.h>
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    int front =p/2;
    int back=(n/2)-(p/2);
    printf("%d\n",front<back?front:back);
    return 0;
}