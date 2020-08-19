#include<stdio.h>
#include<string.h>
char s[10010];
char p[10010];
int dp[1010][1010];
bool s2(){// 专业题解
    memset(dp, 0, sizeof(dp));
    int m,n;
    for(m = 0;s[m];m++);
    for(n = 0;p[n];n++);
    for(int i=1;i<=n;i++){
        if(p[i-1]=='*') dp[0][i] = 1;
        else break;
    }
    
    dp[0][0] = 1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*') dp[i][j] = dp[i-1][j-1] | dp[i][j-1];
            else if(p[j-1]=='?'||p[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[m][n];
}
bool s1(){
    scanf("%s %s",s,p);
    
    int i=0,j=0;
    int m = 0,l = 0,n = 0;
    for(j = 0; s[j];j++);
    for(i = 0; p[i];i++);
    if(j == 0){
        for(i = 0;p[i];i++)
            if(p[i]!='*') return false;
        return true;
    }
    if(i==0){
        if(j==0) return true;
        return false;
    }
    memset(dp, 0, sizeof(dp));
    if(p[0]=='*') for(int i=0;s[i];i++) dp[0][i] = 2;
    else if(p[0]=='?' || p[0] == s[0]) dp[0][0]  = l =1;
    else return false;
    for(m = 0;s[m];m++);
    for(n = 0;p[n];n++);

    for(i = 1;p[i];i++){
        if(!s[l]){
            if(p[i]!='*') return 0;
            if(dp[i-1][m-1])
                dp[i][m-1] = 2;
        }
        for(j = l;s[j];j++){
            if(p[i] == '*' ){
                //printf("%d %d\n",i,j);
                if(j==0) dp[i][j] = 2;
                else if(dp[i][j-1]) dp[i][j] = 2;
                else if(dp[i-1][j]==2) dp[i][j]  = 2;
                else if(dp[i-1][j-1] == 1) dp[i][j]  = 2;
                else if(dp[i-1][j]==1&&!s[j+1]) dp[i][j]  = 1;
            }
            else if(p[i]=='?' || p[i] == s[j]){
                if(j==0){
                    if(dp[i-1][j] == 2) dp[i][j] = 1;
                }
                else{
                    if(dp[i-1][j] == 2) dp[i][j] = 1;
                    else if(dp[i-1][j-1]) dp[i][j] = 1;
                }
            }
        }
        if(p[i]!='*'){l++;}
    }
    for(j = 0; s[j];j++);
    for(i = 0; p[i];i++);
    printf(" ");
    for(int j=0;s[j];j++)
        printf("%c ",s[j]);
    puts("");
    for(int i=0;p[i];i++){
        printf("%c",p[i]);
        for(int j=0;s[j];j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
    return dp[i-1][j-1];
}

int main(){
    printf("%d\n",s2());
    return 0;
}
