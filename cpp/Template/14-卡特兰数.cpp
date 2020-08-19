#include<iostream>
using namespace std;
// 卡特兰数 卡特兰数递推式子满足 f[n] = sum(n-1,0)f[i]*f[n-i-1];
// 卡特兰数 通项变形 f[n] = C(2n,n) - C(2n,n-1) = C(2n,n)/(n+1) 使用排列组合来得到卡特兰数
// C(n,m)  = (n!)/(m!*(n-m)!)
class Solution {
public:
    int numTrees(int n) {
        dp = new int[n+10]{0};
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for(int i=3;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i]+=dp[j]*dp[i-j-1];
        printf("%d\n",dp[n]);
        return dp[n];
    }
private:
    int *dp;
};
int main(){
    Solution *aa = new Solution;
    aa->numTrees(1);
}
