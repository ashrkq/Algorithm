#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sum1[100010];
    int sum2[100010];
    int flag[100010];
    int sum3[100010];
    int minimumOperations(string leaves)
    {
        string &s = leaves;
        int l = leaves.size();
        for (int i = 1; i <= l; i++)
        {
            if (leaves[i - 1] == 'r')
            {
                sum1[i] = sum1[i - 1] + 1;
                sum2[i] = sum2[i - 1];
            }
            else
            {
                sum2[i] = sum2[i - 1] + 1;
                sum1[i] = sum1[i - 1];
            }
        }
        int summ = 0;
        if (s[l - 1] == 'y')
            flag[l] = l, summ = 1;
        else
            flag[l] = l, summ = -1;
        sum3[l] = summ;
        for (int i = l - 1; i > 0; i--)
        {
            if (leaves[i - 1] == 'y')
                summ++;
            else
                summ--;
            if (summ < sum3[flag[i + 1]])
                flag[i] = i;
            else
                flag[i] = flag[i + 1];
            sum3[i] = summ;
        }
        int minn = l;
        for (int i = 1; i < l - 1; i++)
        {
            int k = flag[i + 1];
            if (k == i + 1)
                k = flag[k + 1];
            minn = min(minn, sum2[i] + sum2[l] - sum2[k - 1] + sum1[k - 1] - sum1[i]);
        }
        return minn;
    }
};