#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int n,k;
    char s[10000];
    scanf("%d %s %d",&n,s,&k);
    k%=26;
    for(int i=0;s[i];i++){
        if(isupper(s[i]) )s[i]='A'+(s[i]-'A'+k)%26;
        else if(islower(s[i]))s[i]='a'+(s[i]-'a'+k)%26;
        
    }
    printf("%s\n",s);
    return 0;
}
