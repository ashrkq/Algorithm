#include<stdio.h>
#include<algorithm>
using namespace std;
// 完全背包 每个物品可以使用兑换无数次
// 先枚举背包的大小然后每次选择所有的元素看否符合大小装入即可
int dp[100010];
int c[510];
int v[510];
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d %d",&c[i],&v[i]);
    for(int i=0;i<n;i++)
        for(int j=c[i];j<=m;j++)
            dp[j] = max(dp[j-c[i]]+v[i],dp[j]);
    printf("%d\n",dp[m]);
    return 0;
}

