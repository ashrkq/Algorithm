#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
// map 用法 保存每个树出现的最右端
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans = 0;
        int summ = 0, k = -2;
        m[0] = -1;
        for(int i = 0;i<nums.size();i++){
            summ+=nums[i];
            if(m[summ-target])
                if(m[summ-target] >= k)
                    k = m[summ],ans++;
            m[summ] = i+1;
        }
        return ans;
    }
private:
    map<int,int> m;
};

// map 用法 用来计算两个接待的最近公共祖先
map<string,string> m;
map<string,bool> vis;
string DFS(string &s){
    if(vis[s]){
        return s;
    }
    vis[s] = true;
    if( m[s]!="")
        return DFS(m[s]);
    return m[s];
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string fa,sn;
        cin>>fa>>sn;
        m[sn] = fa;
    }
    int m; scanf("%d",&m);
    while(m--){
        vis.clear();
        string s1,s2;
        cin>>s1>>s2;
        DFS(s1);
        s1 = DFS(s2);
        if(s1!="")
            cout<<s1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
