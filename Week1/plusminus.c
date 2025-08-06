#include<stdio.h>
int main(){
    int pos=0,neg=0,total,zero=0;
    scanf("%d",&total);
    int arr[total];
    for(int i=0;i<total;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>0)
        pos++;
        else if (arr[i]<0)
        neg++;
        else
         zero++;
        }
       printf("%.6f\n",(float)pos/total);
       printf("%.6f\n",(float)neg/total);
       printf("%.6f\n",(float)zero/total);
       
        return 0;
    
    
}
