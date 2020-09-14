#include <bits/stdc++.h>
using namespace std;
#define INF 1000010
#define LL long long
LL tree[4 * INF];
LL lazy[4 * INF];
// 线段树区间更新，用来lazy标记来标记区间的子是否需要更新 更新需要的值是多少
void build(int l, int r, int node)
{
    if (l == r)
    {
        scanf("%lld", &tree[node]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, (node << 1) + 1);
    build(mid + 1, r, (node << 1) + 2);
    tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
}

void check_node(int node, int l, int r, int mid)
{
    if (lazy[node])
    {
        tree[(node << 1) + 1] = lazy[node] * (mid - l + 1);
        tree[(node << 1) + 2] = lazy[node] * (r - mid);
        lazy[(node << 1) + 1] = lazy[node];
        lazy[(node << 1) + 2] = lazy[node];
        lazy[node] = 0;
    }
}

LL query(int l, int r, int node, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tree[node];
    int summ = 0;
    int mid = (l + r) >> 1;
    check_node(node, l, r, mid);
    if (qr <= mid)
        summ = query(l, mid, (node << 1) + 1, ql, qr);
    else if (mid < ql)
        summ = query(mid + 1, r, (node << 1) + 2, ql, qr);
    else
        summ = query(l, mid, (node << 1) + 1, ql, mid) + query(mid + 1, r, (node << 1) + 2, mid + 1, qr);
    return summ;
}

void update(int l, int r, int node, int ql, int qr, LL value)
{
    if (ql <= l && r <= qr)
    {

        lazy[node] = value;
        tree[node] = value * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    check_node(node, l, r, mid);
    if (qr <= mid)
        update(l, mid, (node << 1) + 1, ql, qr, value);
    else if (ql > mid)
        update(mid + 1, r, (node << 1) + 2, ql, qr, value);
    else
    {
        update(l, mid, (node << 1) + 1, ql, mid, value);
        update(mid + 1, r, (node << 1) + 2, mid + 1, qr, value);
    }
    tree[node] = tree[(node << 1) + 1] + tree[(node << 1) + 2];
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
        int q;
        scanf("%d", &q);
        if (q)
        {
            int l, r;
            LL v;
            scanf("%d %d %lld", &l, &r, &v);
            update(0, n - 1, 0, l - 1, r - 1, v);
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(0, n - 1, 0, l - 1, r - 1));
        }
    }
    return 0;
}