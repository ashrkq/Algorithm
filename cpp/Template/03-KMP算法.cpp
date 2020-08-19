#include<stdio.h>
// KMP 算法字符串的匹配算法
int next[10010]; // 存储的是最长前后缀的个数而不是位置
char s[10010];
char ss[1000010];

void build_next1(){
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(s[i]){
        if(j==-1||s[i]==s[j]){
            i++;j++;
            if(s[i]==s[j]) // KMP的优化
                // 如果当前字符和找的的字符是一样的话
                // 我们就找更靠前的字符串
                next[i] = next[j];
            else
                next[i] = j;
        }
        else
            j = next[j];
    }
}
void build_next(){
    int key=0;
    next[0] = -1;
    for(int i=1;s[i];i++){
        if(s[i] == s[key]){
            key++;
            next[i+1] = key;
        }
        else{
            while(key!=-1&&s[i]!=s[key])
                key = next[key];
            if(key==-1){
                key++;
                next[i+1] = key;
            }
            else{
                key++;
                next[i+1] = key;

            }
        }
    }
}
int quire(){
    scanf("%s",ss);
    int k = 0;
    int j = 0;
    int ans = 0;
    while(ss[k]){
        if(ss[k] == s[j]){
            k++;j++;
        }
        else{
            while (j!=-1 && ss[k] != s[j])
                j = next[j];
            j++;
            k++;
        }
        if(!s[j]){ ans++;j=next[j];}

        //printf("%d ****** %d\n",j,k);
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    while (n--){
    scanf("%s",s);
    build_next();
//    for(int i=0;s[i];i++)
//        printf("%c~~~%d----%d\n",s[i], next[i+1], i);
    printf("%d\n",quire());
    }
    return 0;
}
