#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int **dp;
int *w;
int how_one(int n){
    int ans = 0;
    while(n){
        if(n&1) ans++;
        n>>=1;
    }
    return ans;
}
void init(int n,int m){
    dp = (int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<=n;i++){
        dp[i] = (int *)malloc(sizeof(int)*(m+1));
        memset(dp[i], 0, sizeof(int)*(m+1));
    }
}
int main(){

    int n ,m, q; scanf("%d %d %d",&n,&m,&q);
    int pp = (1<<(m-1))-1;  // 2 的m次方可以直接位操作求
    w=(int *)malloc(sizeof(int)*(n+1));
    init(n, pp);
    for(int i=1;i<=n;i++) scanf("%d",w+i);
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=pp;j++){
            if(how_one(j)<q)
                dp[i][(j>>1)+(1<<(m-2))] = max(dp[i-1][j]+w[i],dp[i][(j>>1)+(1<<(m-2))]);
            dp[i][j>>1] = max(dp[i][j>>1],dp[i-1][j]);
            // dp 状态压缩 每次转移都是查找前面m-1个的状态。
            // 如果小于q就把本为状态制为1然后就本位为1的状态就会变成
            // 前一位少了一位的状态+本位的值
            // 否则我们就等于本状态为0 前一个状态少一位的值
            
        }
    }
    int minn = 0;
    for(int i=0;i<=pp;i++) minn = max(minn,dp[n][i]);
    printf("%d\n",minn);
    return 0;
}
