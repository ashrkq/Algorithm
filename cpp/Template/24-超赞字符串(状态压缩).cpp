#include<iostream>
#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
// 找出最长的超赞子字符串 状态压缩
// 总共10个数字，stat表示0-i的状态 dp[i] 记录了每个状态的最左边的位置
// 每个状态 只能和在自己完全一样或者只有一个位置不一样的状态才可以组成回文串
// 使用异或的性质相同为1不同为0来找到每个和自己状态之差一个的状态
// 使用异或找到另一个状态和自己有什么不同 &
class print_num{
public:
    int operator()(char c){
        return c-'0';
    }
};
class print_arr{
public:
    void operator()(int c){
        cout<<c<<" ";
    }
};
class Solution {
public:
    void init(int n){
        dp = new int[1024];
        for(int i=0;i<1024;i++) dp[i] = -1;
        arr.resize(n);
    }
    int longestAwesome(string s) {
        int maxx = 1, n = static_cast<int>(s.size()); init(n);
        transform(s.begin(), s.end(), arr.begin() ,print_num());
        // for_each(arr.begin(), arr.end(), print_arr());
        int stat = 0;
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int k = 1<<arr[i-1];
            stat ^= k;
            if(dp[stat]==-1)
                dp[stat] = i;
            for(int j=0;j<=10;j++){
                int ans = j==10?stat:stat^(1<<j);
                int k = ans;
                if(dp[k] == -1) continue;
                ans ^= stat;
                int x = 0;
                while(ans){
                    if(ans&1) x++;
                    ans>>=1;
                }
                if(x<=1)
                    maxx = max(maxx, i-dp[k]);
            }
        }
        return maxx;
    }
private:
    int *dp;
    vector<int> arr;
};
