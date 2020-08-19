#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
// 最多的不重叠子字符串
// 使用贪心的思想。从最短的满足的字符串开始选取优化更新每隔选取到的区间
// 每次把满足的区间选取到想要的地方
class Solution {
public:
    void init(int const &n, string &s){
        be = new int[26]{0};
        ed = new int[26]{0};
        vis = new bool[n]{0};
        for(int i=0;i<n;i++){
            ed[s[i]-'a'] = i+1;
            be[s[i]-'a'] = be[s[i]-'a']?be[s[i]-'a']:i+1;
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> v;
        int n = (int)s.size();
        init(n, s);
        for(int i=0;i<26;i++){
            int b = be[i];
            int e = ed[i];
            int K = 1;
            if(b==e && b == 0) continue;
            printf("%d %d %d\n",b,e,i);
            for(int j = b-1;j<e;j++){
                if(b > be[s[j]-'a']){
                    K= 0; break;
                }
                if(e < ed[s[j] - 'a'])
                    e = ed[s[j] -'a'];
            }
//            puts("sdfsadfsadfsdfa");

            if(K) vs.push_back(ad{s.substr(b-1,e - b+1),e-b+1,e,b});
        }
        vs.push_back(ad{s,n,n+1,1});
        sort(vs.begin(), vs.end());
        vector<ad>:: iterator it;
        for(it = vs.begin();it != vs.end(); ++it){
            int K= 1;
            for(int i=it->b-1;i<it->e;i++){
                if(vis[i]){ K = 0; break;}
            }
            if(K){
                for(int i=it->b-1;i<it->e;i++){
                    vis[i] = true;
                }
                v.push_back(it->sr);
                cout<<it->n<<"***"<<it->sr<<endl;
            }
            
        }
        return v;
    }
private:
    struct ad{
        string sr;
        int n;
        int e,b;
        bool operator <(const ad&b)const{return n<b.n;}
    };
    vector<ad> vs;
    int *be;
    int *ed;
    bool *vis;
};
int main(){
//    string s = "aaabbbb";
//    cout<<s.substr(2,5-2);
    Solution s;
    string st;
    cin>>st;

    s.maxNumOfSubstrings(st);
    return 0;
}
