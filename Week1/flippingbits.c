#include<stdio.h>
int main(){
    int q;
    unsigned int n;
    scanf("%d",&q);
    while(q--){
        scanf("%u",&n);
        printf("%u\n",~n);
    }
    return 0;
}