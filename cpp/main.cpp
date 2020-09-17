#include<bits/stdc++.h>
using namespace std;
#define INF 100010
vector<pair<int, int>> paper;
vector<int> colors;
vector<int> ln;
map<int, int> idx;
int num;
int tree[INF * 4];
int lazy[INF * 4];
bool vis[INF];
// 线段树的区间覆盖问题，离散化计算数据使用
// 区间覆盖，问题每次更新区间然后最后查询区间中的颜色有几种
// 使用左封右开的区间查询。区间颜色l-r就是l-r来标记标记的使用的第几个区间
void build(int l, int r, int node){
    if(l == r-1){
        tree[node] = -1; return ;
    }
    int mid = (l + r ) >> 1;
    build(l, mid, node<<1);
    build(mid, r, node<<1|1);
}

void push_down(int mid, int node, int l, int r){
    if(lazy[node]){
        lazy[node << 1] = lazy[node << 1|1] = lazy[node];
        tree[node << 1] = tree[node << 1|1] = lazy[node];
        lazy[node] = 0;
    }
}

void update(int l, int r, int node, int ql, int qr, int value){
    if(ql <= l && r <= qr){
        tree[node] = value;
        lazy[node] = value;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(mid, node, l, r);  
    if( ql < mid) update(l, mid, node<<1, ql, qr, value);
    if(qr > mid) update(mid, r, node<<1|1, ql, qr, value);
}

void query(int l, int r, int node){
    if(l == r - 1){
        if(tree[node] != -1 && !vis[tree[node]]){
            vis[tree[node]] = true;  colors.push_back(tree[node]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    push_down(mid, node, l, r);
    query(l, mid, node << 1);
    query(mid, r, (node << 1) + 1);
}
int main(){
    int n,l; scanf("%d %d", &n, &l);
    for(int i=0;i<n;++i){
        int a, b; scanf("%d %d", &a, &b);
        paper.push_back({a,b});
        ln.push_back(a); ln.push_back(b);
    }
    sort(ln.begin(), ln.end());
    for(int a : ln) if(!idx[a]) idx[a] = ++num;
    if(idx[l]) idx[l+1] = ++num;
    else idx[l] = ++num;
    build(1, num, 1);
    int m = 1;
    for(auto id:paper) update(1, num, 1, idx[id.first], idx[id.second], m++);
    query(1, num, 1);
    printf("%lu\n",colors.size());
    return 0;
}