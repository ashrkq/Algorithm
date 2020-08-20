#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// 树形dp 树上一个区间最大的权值和
// dp[i][j] 表示 包含i节点的 长度为j的最大权值
struct Node{
    int v;
    Node*nt;
}**node;
int **dp;
int *value;
int n,m;
void init(int n,int m){
    node = (Node**)malloc(sizeof(Node*)*n);
    value = (int*)malloc(sizeof(int)*n);
    memset(node,0,sizeof(Node*)*n);
    dp= (int**)malloc(sizeof(int*)*n);
    for(int i=1;i<=n;i++) dp[i] = (int*)malloc(sizeof(int)*m),memset(dp[i],0,sizeof(int)*m);
}
void add(int u,int v){
    Node* nt = (Node*)malloc(sizeof(Node*));
    nt->v = v; nt->nt = node[u]; node[u] = nt;
}
void DFS(int u,int fa){
    dp[u][1] = value[u];
    for(Node *it = node[u];it!=NULL;it =it->nt){
        int v = it->v;
        if(v == fa) continue;
        DFS(v, u);
        for(int i=m;i>=2;i--) // 从大向小遍历 从小向大遍历 小的数据会对大的数据造成影响
            for(int j=1;j<i;j++)
                dp[u][i] = max(dp[v][j]+dp[u][i-j],dp[u][i]);
    }
}
int main(){
    cin>>n>>m;
    init(n+1,m+1);
    for(int i=1;i<=n;i++) cin>>value[i];
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        add(u, v); add(v, u);
    }
    DFS(1, 0);
    int maxx = 0;
    for(int j=1;j<=m;j++) maxx = max(maxx, dp[1][j]);
    cout<<maxx<<endl;
    return 0;
}
