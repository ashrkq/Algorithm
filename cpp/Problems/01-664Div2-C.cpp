#include<bits/stdc++.h>
using namespace std;
int a[300];
int b[300];
bool vis[300];
// 每次贪心找到最小之中 或出来的最大的那个值
int main(){
    int n,m; scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", b+i);
    int ans = 0;
    for(int i=0;i<n;i++){
        int maxx = 0,flag=0;
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            int minn = a[j]|ans;
            for(int k=0;k<m;k++)
                if(((a[j]&b[k])|ans)< minn)
                    minn = (a[j]&b[k])|ans;
            if(minn >= maxx)
                maxx = minn,flag = i;
        }
        ans |= maxx;
        vis[flag] = true;
    }
    printf("%d\n",ans);
    return 0;
}