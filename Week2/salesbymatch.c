#include<stdio.h>
int sockMerchant(int n,int arr[]){
    int count[101] = {0}, pairs=0;
    for(int i=0;i<n;i++)
    count[arr[i]]++;
    for(int i=1;i<=100;i++)
    pairs += count[i]/2;
    return pairs;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("%d\n",sockMerchant(n,arr));
    return 0;
}