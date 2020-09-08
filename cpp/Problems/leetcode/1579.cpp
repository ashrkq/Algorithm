#include<bits/stdc++.h>
using namespace std;
// 使用并查集维护两个生成树
// 如果是优先遍历两个人共享的边如果有人两个人都通了就舍弃这条边
// 分别遍历每个人的边 如果两个点已经联通就舍弃
// 最后判读两个图是否都联通
class Solution {
public:
    void init(int n){
        pre1 = (int*)malloc(sizeof(int)*n);
        pre2 = (int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++) pre1[i] = pre2[i] = i;
    }
    int find(int x, int * &pre){
        return pre[x] == x ? x : pre[x] = find(pre[x], pre);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        init(n+1);

        for(vector<int> arr : edges){
            if(arr[0] == 3){
                int x1 = find(arr[1], pre1), y1 = find(arr[2], pre1);
                int x2 = find(arr[1], pre2), y2 = find(arr[2], pre2);
                if(x1 == y1 && x2 == y2) ans++;
                else pre1[x1] = y1, pre2[x2] = y2;
            }
        }
        for(vector<int> arr : edges){
            if(arr[0] == 1){
                int x = find(arr[1], pre1), y = find(arr[2], pre1);
                if(x == y) ans++;
                else pre1[x] = y;
            }
            if(arr[0] == 2){
                int x = find(arr[1], pre2), y = find(arr[2], pre2);
                if(x == y) ans++;
                else pre2[x] = y;
            }
        }
        int k1 = 0 ,k2 = 0;
        for(int i=1;i<=n;i++) if(i == find(i, pre1)) k1++;
        for(int i=1;i<=n;i++) if(i == find(i, pre2)) k2++;
        if(k1 != 1 && k2 != 1) return -1;
        return ans;
    }
    ~Solution(){
        free(pre1);
        free(pre2);
    }
private:
    int *pre1, *pre2;
};