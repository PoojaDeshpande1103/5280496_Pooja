#include<stdio.h>
int main(){
    int min,max;
    long int total = 0;
    int arr[5];
    for (int i =0;i<5;i++){
        scanf("%d",&arr[i]);
        total += arr[i];
    }
    min=max=arr[0];
    for(int i=0;i<5;i++){
        if(arr[i]<min)min = arr[i];
        if(arr[i]>max)max = arr[i];
    }
    printf("%ld %ld\n",total - max,total- min);
    return 0;
}
