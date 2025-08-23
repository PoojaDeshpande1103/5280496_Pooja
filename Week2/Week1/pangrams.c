#include<stdio.h>
#include<ctype.h>
#include<string.h>
char* pangrams(char* s){
    int letters[26] = {0};
    int count = 0;
    for(int i=0;s[i];i++){
        if(isalpha(s[i])){
            int x = tolower(s[i])-'a';
            if(!letters[x]){
                letters[x]=1;
                count++;
            }
        }
        
    }
    return (count==26)?"pangram":"not pangram";
}
int main(){
    char s[1000];
    fgets(s, sizeof(s),stdin);
    printf("%s",pangrams(s));
    return 0;
}