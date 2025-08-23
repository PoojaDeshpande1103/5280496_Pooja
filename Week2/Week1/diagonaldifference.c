#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int firstsum =0,secondsum =0, num;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&num);
            if(i==j)
            firstsum +=num;
            if(i+j==n-1)
            secondsum +=num;
        }
    }
    printf("%d",abs(firstsum - secondsum));
    return 0;
}