#include<bits/stdc++.h>
using namespace std;
#define INF 100010
int pre[INF];
map<string,int> mp;
map<int,string> mm;
vector<int> tr[INF];
vector<int>query_set[INF];
int cnt;
string qr1[INF];
string qr2[INF];
int ans[INF];
// 最近公共祖先，先记录所有的查询。
// dfs遍历每个节点的位置dbf每个节点第一次遍历到
// 如过这个节点需要查找的点已经被遍历到了就查找
// 这个节点的最近的还没有dfs遍历完的节点
// 记录这个节点的最近没有被dfs结束的节点使用并查集维护
int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
}
void dfs(int x,int fa){
    pre[x] = x;
    for(int a: tr[x]) dfs(a, x);
    for(int t : query_set[x]){
        // 过的该节点的被查询了的节点和他的答案
        int s = x==mp[qr2[t]]?mp[qr1[t]]:mp[qr2[t]];
        if(pre[s] == -1) continue;
        ans[t] = find_root(s);
    }
    pre[x] = fa;
}
int main(){
    int n; scanf("%d",&n);
    string s1,s2;
    memset(pre, -1, sizeof(pre));
    while(n--){
        cin>>s1>>s2;
        // 使用0的会出现覆盖的情况
        if(!mp[s1]) mp[s1] = ++cnt,mm[cnt]=s1;
        if(!mp[s2]) mp[s2] = ++cnt,mm[cnt]=s2;
        int f = mp[s1], s = mp[s2];
        tr[f].push_back(s);
    }
    int m; scanf("%d", &m);
    for(int i=0;i<m;i++){
        cin>>s1>>s2; // 记录查询的位置
        qr1[i] = s1; qr2[i] = s2;
        int r1 = mp[s1], r2 = mp[s2];
        query_set[r1].push_back(i);
        query_set[r2].push_back(i);
    }
    dfs(1,0); 
    for(int i=0;i<m;i++)
        cout<<mm[ans[i]]<<endl;
    return 0;
}