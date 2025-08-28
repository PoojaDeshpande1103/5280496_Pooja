#include <stdio.h>
int towerbreakers(int n,int m){
    if(m==1||n%2==0)
    return 2;
    else
    return 1;
}
int main(){
    int t, n, m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        printf("%d\n",towerbreakers(n,m));
        
    }
    return 0;
}