#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxxl[510][510];
    int maxxr[510][510];
    void init(int n){
        summ = static_cast<int*>(malloc(sizeof(int)*n));
        memset(summ, 0, sizeof(int)*n);
        dp = (int**)malloc(sizeof(int*)*n);
        for(int i=0;i<n;i++){ 
            dp[i] = (int*)malloc(sizeof(int)*n);
            memset(dp[i], 0, sizeof(int)*n);
        }
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = static_cast<int>(stoneValue.size());
        init(n+1);
        for(int i=1;i<=n;i++) summ[i] = summ[i-1]+ stoneValue[i-1];
        for(int ln=1;ln<=n;ln++){
            int mid = 1;
            for(int i=1;i+ln-1 <= n;i++){ 
                int k = i+ln-1;
                // 对区间dp进行优化
                // 每次大于的和小于的都要被一个点分割
                // 分别求出左右两边的最值 然后选取最值就可以了
                // maxxl[i][j]表示似选取mid左边的mid到i
                // maxxr[i][j] 表示选取mid右边到mid到j
                while(summ[mid]-summ[i-1] < summ[k]-summ[mid]) mid++;
                if(mid>i) dp[i][k] = max(dp[i][k], maxxl[i][mid-1]);
                if(mid<=k) dp[i][k] = max(dp[i][k], maxxr[mid][k]);
                if(summ[mid]-summ[i-1] == summ[k]-summ[mid]) dp[i][k] = max(dp[i][k], maxxl[i][mid]);
                maxxl[i][k] = max(maxxl[i][k-1],dp[i][k] + summ[k] -summ[i-1] );
                maxxr[i-1][k] = max(maxxr[i][k],dp[i][k] + summ[k] -summ[i-1] );
            }
        }
        return dp[1][n];
    }
private:
    int **dp;
    int *summ;
};
int main(){
    return 0;
}