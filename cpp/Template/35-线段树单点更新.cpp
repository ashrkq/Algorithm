#include <bits/stdc++.h>
using namespace std;
int wit[1000010];
int tree[4 * 1000010];
// 线段树 单点更新
// 把一个序列每次二分 每个节点代表一个区间 每个节点记录了这个区间的最小值
// 依次递归更新区间的最值
// 依次向上更新 使用了堆的结构 以数组的方式存储
void build(int l, int r, int idx)
{
    if (l == r)
    {
        scanf("%d", tree + idx);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, (idx << 1) + 1);
    build(mid + 1, r, (idx << 1) + 2);
    tree[idx] = min(tree[(idx << 1) + 1], tree[(idx << 1) + 2]);
}
int query(int l, int r, int idx, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(l, mid, (idx << 1) + 1, ql, qr);
    if (ql > mid)
        return query(mid + 1, r, (idx << 1) + 2, ql, qr);
    return min(query(l, mid, (idx << 1) + 1, ql, mid), query(mid + 1, r, (idx << 1) + 2, mid + 1, qr));
}
void update(int l, int r, int idx, int x, int value)
{
    if (l == r)
    {
        tree[idx] = value;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= x)
        update(l, mid, (idx << 1) + 1, x, value);
    else
        update(mid + 1, r, (idx << 1) + 2, x, value);
    tree[idx] = min(tree[(idx << 1) + 1], tree[(idx << 1) + 2]);
}

int main()
{
    int n;
    scanf("%d", &n);
    build(0, n - 1, 0);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int q, x, y;
        scanf("%d %d %d", &q, &x, &y);
        if (q)
            update(0, n - 1, 0, x - 1, y);
        else
            printf("%d\n", query(0, n - 1, 0, x - 1, y - 1));
    }
    return 0;
}