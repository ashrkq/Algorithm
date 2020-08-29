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