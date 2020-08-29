#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
        // 区间dp 标准模版一般会使用优化 dp[i][j] 表示在区间i,j之间的最优值
        for(int ln=1;ln<=n;ln++){ //  区间dp 设置区间的长度
            for(int i=1;i+ln-1 <= n;i++){ // 设置区间的其实位置
                int k = i+ln-1;
                for(int mid=i;mid<k;mid++){ // 枚举区间中的中间点的
                    // 这个题目的优化方法 因为是summ是递增的
                    // 可以找到一个点mid 这个点之后的点都以sum1 > sum2
                    // 定义两个集合存储dp[i][k] + sum [i][k]左侧区间的值 和右侧的值
                    int sum1 = summ[mid] - summ[i-1], sum2 = summ[k] - summ[mid];
                    if(sum1 >= sum2)
                        dp[i][k] = max(dp[i][k], dp[mid+1][k]+sum2);
                    if(sum2 >= sum1)
                        dp[i][k] = max(dp[i][k], dp[i][mid]+sum1);
                }
            }
        }
        return dp[1][n];
    }
    ~Solution(){
        free(dp);
        free(summ);
    }
private:
    int **dp;
    int *summ;
};
int main(){
    return 0;
}