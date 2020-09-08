
#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<int,string> mp2;
vector<int> edge[100010];
int dx[200010][20], in[100010],node[200010][20];
int cnt, num;
// LCA 在线算法 可以用来写这个代码
// 使用DFS序 把一个树变成了一个序列
// 记录每个节点第一次进入的时间 然后连个节点之间深度最浅的点就是两个节点父节点
// 使用RMQ中的ST算法可以快速找到每个区间内的最小值 顺便记录最小值的位置
void DFS(int fa, int deep){
    in[fa] = ++num; 
    dx[num][0] = deep;
    node[num][0] = fa;
    for(int a:edge[fa]){ 
        DFS(a, deep+1);
        dx[++num][0] = deep;
        node[num][0] = fa;
    }
}
void init(){
    for(int j=1;1<<j<=num ;j++)
        for(int i=1;(i + (1<<j)) - 1<= num;i++){
            dx[i][j] = min(dx[i][j-1],dx[i + (1<<(j-1))][j-1]);
            if( dx[i][j-1] < dx[i+(1<<(j-1))][j-1]) node[i][j] = node[i][j-1];
            else node[i][j] = node[i+(1<<(j-1))][j-1];
        }
}
int main(){
    int n; scanf("%d", &n);
    string s1,s2;
    while(n--){
        cin>>s1>>s2;
        if(!mp[s1]) mp[s1] = ++cnt, mp2[cnt] = s1;
        if(!mp[s2]) mp[s2] = ++cnt, mp2[cnt]= s2;
        int fa = mp[s1], son = mp[s2];
        edge[fa].push_back(son);
    }
    DFS(1,1);  init();
    int m; scanf("%d", &m);
    while(m--){
        cin>>s1>>s2;
        int k1 = in[mp[s1]], k2=in[mp[s2]];
        int ln = static_cast<int>( log2( abs(k1 - k2) + 1 ) );
        int l = min(k1, k2);
        int r = max(k1, k2);
        if (dx[l][ln] < dx[r-(1<<ln) + 1][ln]) cout<< mp2[node[l][ln]]<<endl;
        else cout<<mp2[node[r-(1<<ln) + 1][ln]]<<endl;  
    }
    return 0;
}