#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 行程长度编码
// dp[i][j] 表示到达第i个元素删除了j个
// 对于第i个元素有两种状态
class Solution {
public:
    int lenn(int x){
        if(x == 1) return 1;
        else if(x>=10&&x<100) return 3;
        else if(x>=100) return 4;
        else return 2;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = (int)s.size();
        dp = new int*[n+1];
        for(int i=0;i<=n;i++) dp[i] = new int[k+1];
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = 0x7fffffff;
        for(int i=0;i<=k;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k&&j<=i;j++){
                if(j<k) dp[i][j+1] = min(dp[i][j+1],dp[i-1][j]);  // 状态1 直接删除掉那么dp[i][j] = dp[i-1][j-1]
                int summ = 0;
                int dell = 0;
                for(int w = i;w<=n;w++){ // 状态2 如果这个元素不选择删除优先更新后面的元素优先删除和其不一样的元素
                    if(s[w-1] == s[i-1]) summ++;
                    else dell++;
                    if(dell+j<=k) dp[w][j+dell] = min(dp[w][j+dell],lenn(summ)+dp[i-1][j]);
                    else break;
                }
            }
        }
        return dp[n][k];
    }
private:
    int **dp;
};
