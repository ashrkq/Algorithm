#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = static_cast<int>(position.size());
        sort(position.begin(), position.end());
        int l = 1;
        int r = (position[n-1] - position[0])/(m-1);
        int ans = 1;
        while(l<r){
            int mid = (l+r+1) >> 1;
            int cnt = 0, pre = -1000000000;
            for(int i=0;i<n;i++){
                int dis = position[i] - pre;
                if(dis >= mid){
                    cnt++;
                    pre = position[i];
                }
            }
            if(cnt>=m) l = mid;
            else r = mid-1;
        }
        return r;
    }
};