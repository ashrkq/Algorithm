#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int mod = 1e9+7;
int **dp;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int lmax = 1<<(m<<1); // 总共把1移动了2m个位置
    int ln = (1<<m) -1;
    dp = new int*[n+1];
    for(int i=0;i<=n;i++) dp[i] = new int[lmax]{0};
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k = 0;k<lmax;k++)
                // 因为从上到下放制会发现所有的都是可以竖着放的。竖着放的位置永远是可以放下的
                if(((1<<j)&k)==0){ // 判断这个位置是不是可以放得下
                    if(j != m-1 && ((1<<(j+1))&k)==0) // 判断是不是可以横着放
                        dp[i][k|(1<<j)|(1<<(j+1))] = (dp[i][k|(1<<j)|(1<<(j+1))]+dp[i][k])%mod;
                    if(((1<<(m+j))&k)==0) // 判断是否可以竖着放下 这个判断可以不写
                        // 因为从上向下从左向右的放置可以拍保证在地j个位置是空的一定可以竖着放
                        dp[i][k|(1<<(m+j))|(1<<j)] = (dp[i][k|(1<<(m+j))|(1<<j)] + dp[i][k])%mod;
                }
            for(int k=0;k<lmax;k++) // 把这一行已经放满状态转移到下一行
                if((k&ln) == ln )
                    dp[i+1][k>>m] = dp[i][k];
                
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
