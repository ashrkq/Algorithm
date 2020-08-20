#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
// 区间dp dp[i][j] 表示从第i个点到j个点的最小值
// dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j] + cuts[j] - cuts[i])
// 类似最短路径中的floy算法 三重循环 从大到小遍历
class Solution {
public:
    void init(int n){
        dp = new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[n]{0};
            for(int j=0;j<n;j++) dp[i][j] = 0xfffffff;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = static_cast<int>(cuts.size());
        init(m);
        sort(cuts.begin(), cuts.end());
        for(int i=1;i<m;i++) dp[i][i] = 0,dp[i-1][i] =0;
        dp[0][0] = 0;
        for(int i=m-2;i>=0;i--)
            for(int j=i;j<=m-1;j++)
                for(int k=i;k<j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+ cuts[j] - cuts[i]);
        return dp[0][m-1];
    }
private:
    int **dp;
};
