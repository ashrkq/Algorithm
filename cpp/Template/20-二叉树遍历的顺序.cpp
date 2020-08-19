#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 递归解法
// 二叉树前序遍历=root + 左子树前序遍历 + 右子树前序遍历
// 二叉树中序遍历=左子树中序遍历 + root + 右子树中序遍历
// 二叉树后续遍历=左子树后续遍历 + 右子树后续遍历 + root
// post+order(pre_order,mid_order) =
// post_order(pre_order左子树，mid_order左子树) + post_order(pre_order右子树，mid_order右子树) + root
// 以此类推可以根据任意两个遍历获得新的遍历
void Post(const char *pre,const char *in,int len)
{
    if(len<1) return;
    int i=0;
    while(in[i]!=pre[0]) i++;
    Post(pre+1,in,i);
    Post(pre+i+1,in+i+1,len-i-1);
    printf("%c",pre[0]);
}


bool num[26];
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = (int)s1.size();
    string s3(s1.size(),0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s1[i]==s2[j]){
                int sum = 0;
                for(int k=j-1;k>=0;k--){
                    if(num[k]) break;
                    sum++;
                }
                for(int k=j+1;k<n;k++){
                    if(num[k]) break;
                    sum++;
                }
                int k = 0;
                for(k=0;s3[k]!=0;k++);
                s3[k+sum] = s1[i];
                num[j] = true;
            }
        }
    }
    cout<<s3<<endl;
    return 0;
}

