#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
// 最短路径使用堆优化的模型
struct Edge{
    int u,v;
    double w;
    Edge *next;
}*edge[10010];
void AddEdge(int u,int v,double w){
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->v = u; e->w = w; e->u = u;
    e->next = edge[u]; edge[u] = e;
}
double Dijkstra(int n,int end){
    priority_queue<pair<double, int>> priq;
    while(!priq.empty()) priq.pop();
    bool vis[10010];
    double dis[10010];
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    for(Edge *i = edge[n];i;i=i->next){
        dis[i->v] = i->w;
        priq.push({i->w,i->v});
    }
    vis[n] = true;
    for(int i=0;i<n;i++){
        pair<double,int> e = priq.top();
        priq.pop();
        int u = e.second;
        vis[u] = true;
        for(Edge *i=edge[u];i;i=i->next){
            int v = i->v;
            double w = i->w;
            if(vis[v]&&dis[u]*w>=dis[v]){
                if(dis[v] == 0)
                    dis[v] = w;
                else
                    dis[v] = dis[v]*w;
                priq.push({dis[v],i->v});
            }
        }
    }
    return dis[end];
}
void init(int n){
    for(int i=1;i<n;i++)
        edge[i]->next = NULL;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    init(n);
    int m = (int)edges.size();
    for(int i=0;i<m;i++){
        AddEdge(edges[i][0], edges[i][1],succProb[i]);
        AddEdge(edges[i][1], edges[i][0],succProb[i]);
    }
    return Dijkstra(start,end);

}
int main(){
    
    return 0;
}
