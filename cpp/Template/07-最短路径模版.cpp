#include<stdio.h>
#include<algorithm>
using namespace std;
int Map[100][100];
int dis[10010];
bool vis[110];
int n;
// 最短路径中dijkstra的模版
// 计算单元最短路径N*N
void Dijkstra(int num){
    int minnk = 0x6fffffff;
    int k = num;
    vis[num] = true;
    for(int i=1;i<=n;i++){
        dis[i] = 0x6fffffff;
        if(Map[num][i])
            dis[i] = Map[num][i];
        if(minnk>dis[i]){
            minnk = dis[i]; k = i;
        }
    }
    for(int i=1;i<n;i++){
        minnk = 0x6fffffff;
        for(int j=0;j<n;j++){
            if(!vis[i] && dis[j]<minnk){
                minnk = dis[j];
                k = j;
            }
        }
        vis[k] = true;
        for(int j=0;j<n;j++)
            if(!vis[j]&&dis[j]>Map[k][j]+dis[k])
                dis[j] = Map[k][j];
    }
}
// Floyd 最简单的模版 计算所有点到其他点之间的最短路径n*n*n
void Floyd(){
    for(int k=1;k<=n;k++){ // 第一次循环找到经过k1点可以到达的点或者直接到达的点
        // 找到直接到达的点 或者经过快k2到达的带你 或者经过k1到达的点 或者经过k1，k2到达的点
        // 找到直接到达的点 或者经过快k2到达的带你 或者经过k1到达的点 或者经过k1，k2到达的点 或者经过k3到达的点。。。
        for(int i=1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                Map[i][j] = min(Map[i][k]+Map[k][j],Map[i][j]);
    }
}
int main(){
    n = 30;
    Dijkstra(0);
    return 0;
}
