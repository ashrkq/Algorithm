#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
// 后续遍历一棵树，记录一下之间出现的了多少相同标记
// 没到一个节点就把这个标记加1。回溯回到此节点时
// 跟此节点标记一样的个数就是总个数-之前的记录个数
class Solution {
public:
    void DFS(int u,vector<int> &ans,string &s,int fa){
        int c = s[u] - 'a';
        int k = m[c];
        for(Node *p = node[u];p;p = p->next){
            if(p->v == fa) continue;
            DFS(p->v,ans,s,u);
        }
        m[c]++;
        ans[u] = m[c] - k;
    }
    void init(int n){
        node = new Node*[n]{NULL};
        m = new int[26]{0};
    }
    void add(int u,int v){
        Node *n = (Node*)malloc(sizeof(Node));
        n->v = v; n->next = node[u];
        node[u] = n;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        init(n);
        vector<int> ans(n);
        for(vector<vector<int>>:: iterator it = edges.begin();it!=edges.end(); ++it){
            add(it->at(0), it->at(1));
            add(it->at(1), it->at(0));
        }
        DFS(0,ans,labels,-1);
        return ans;
    }
private:
    struct Node{
        int v;
        Node *next;
    }**node;
    int *m;
};
