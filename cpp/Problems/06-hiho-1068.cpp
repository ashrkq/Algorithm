#include<bits/stdc++.h>
using namespace std;
// RMQ 区间最值查询算法 每次查询区间中的最大者或者最小值
// 中RMQ算法 使用叙述表的方式一O(n*log) 预处理 O(1) 的复杂度查询
// q[i][j] 表示以i 开头后长2^j长度的最小值
// q[i][j] = min(q[i][j-1], q[i+(1<<(j-1))][j-1])
// ans 是比这个区间长度小的最大的 2^ans 
// 查询的时候最小值就是 min(q[l][ans],q[l-(1<<ans)+1][ans])
// 本质思想是找了两个区间可能有重合然后求交集
int pre_calc[1000100][20];
int main(){
    int n; scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &pre_calc[i][0]);

        for(int j=1;1<<j <= n; j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                pre_calc[i][j] = min(pre_calc[i][j-1], pre_calc[i+(1<<(j-1))][j-1]);

    int m; scanf("%d",&m);
    while(m--){
        int l,r; scanf("%d %d",&l,&r);
        int ans = 0;
        while((1<<ans)<=(r-l+1)) ans++; ans--;
        printf("%d\n", min(pre_calc[l][ans], pre_calc[r-(1<<ans)+1][ans]));
    }
    return 0;
}