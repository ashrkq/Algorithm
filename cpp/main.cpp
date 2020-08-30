#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void init(int n){
        di = new bool[n]{0};
        li = new int[n]{0};
        ri = new int[n]{0};
        summ = new int[n]{0};
        for(int i=0;i<n;i++) li[i]=ri[i]=i;
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n = static_cast<int>(arr.size());
        init(n);
        int ans = -1;
        for(int i=0;i<n;i++){
            int a = arr[i]-1;
            di[a] = true;
            int l=li[a], r = ri[a];
            if(a<n-1 && di[a+1]){ 
                r=ri[a+1]; summ[ri[a+1] - li[a+1] +1]--;
            }
            if(a>0 && di[a-1]){
                l=li[a-1]; summ[ri[a-1] - li[a-1] +1]--;
            }
            summ[ri-li+1]++;
            if(summ[m]) ans = i+1;
            printf("%d %d\n",l,r);
            li[a] = l; ri[a] = r;

        }
        return ans;
    }
private:
    bool *di;
    int *li,*ri;
    int *summ;
};
int main(int argc, char const *argv[]){
    return 0;
}
