#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
// 记忆化搜索方法
// dp 最优的解为 1 + min(n%2+f[n/2] ,n%3 + f[n/3])
// 搜索的时候记录已经出现的最小的值，不要做过多的搜索了
class Solution {
public:
    int DFS(int n){
        if(n==0) return 0;
        if(m[n]) return m[n];
        m[n] = 1 + min(n%2+DFS(n/2), n%3 + DFS(n/3));
        return m[n];
    }
    int minDays(int n) {
        m[0] = 1; m[1] = 1;
        return DFS(n);
    }
private:
    map<int, int>m;
};
