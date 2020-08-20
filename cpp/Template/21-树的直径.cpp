#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// 树的直径 两次DFS
// 随便找一点p搜索到一点q
// q找一点搜索最远就是最远路径
// 证明：如果q不是直径的另一个端点 ab为直径
// ab和pq相交于点w  pw>aw pw+wb>aw+wb 矛盾
// ab和pq不相交 ab上一点n pq上一点m 连接nm qm+mn+mb > am+mb 矛盾
// q一定是最长路径上的一个端点

// 树形DP：
// 统计每个节点左右两端的深度。直径就是最大的两个深度相加
struct Node{
    int v;
    Node *nt;
    Node(int x,Node *n):v(x),nt(n){}
}**node;

int maxx;
int ans;
void add(int u, int v){
    Node *n = new Node(v,node[u]);
    node[u] = n;
}
void init(int n){
    node = new Node*[n+1]{NULL};
//    for(int i=0;i<=n;i++) node[i] = new Node(0,NULL);
}
void DFS(int u,int step,int fa){
    if(step > maxx) ans = u,maxx = step;
    for(Node *i = node[u];i!=NULL;i=i->nt)
        if(i->v != fa) DFS(i->v,step+1,u);
}
int main(){
    int n; cin>>n;
    init(n);
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        add(u, v); add(v, u);
    }
    maxx = 0; ans = 1;
    DFS(1,0,0);
    DFS(ans, 0, 0);
    cout<<maxx<<endl;
    return 0;
}
