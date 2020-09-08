#include<bits/stdc++.h>
using namespace std;
// 暴力查找加修改区间的最小值
int num[10010];
int main(){
    int n; scanf("%d", &n);
    for(int i=0;i<n;++i) scanf("%d", num+i);
    int m; scanf("%d", &m);
    while(m--){
        int q, l, r; scanf("%d %d %d", &q, &l, &r);
        if(q) num[l-1] = r;
        else{
            int minn = num[l-1];
            for(int i = l-1; i<r;++i) minn = min(minn,num[i]);
            printf("%d\n", minn);
        }
    }
    return 0;
}