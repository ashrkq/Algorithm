#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[2][100010];
int v[510];
int c[510];
// 经典的01背包问题
// dp[i][j] 拿到第i个物品有j的质量最多能拿到多少
int main(){
    int n ,m;
    scanf("%d %d",&n,&m);
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++) scanf(x"%d %d",&c[i],&v[i]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            int k = i%2;
            if(c[i]<=j){
                if(k==1)
                    dp[k][j] = max(dp[k-1][j-c[i]]+v[i],dp[k-1][j]);
                else
                    dp[k][j] = max(dp[k+1][j-c[i]]+v[i],dp[k+1][j]);
            }
            else{
                dp[k][j] = dp[!k][j];
            }
        }
    }
    printf("%d\n",dp[n%2][m]);
    return 0;
}
