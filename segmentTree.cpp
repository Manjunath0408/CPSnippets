#include <bits/stdc++.h>
using namespace std;
int a[200005];
int tree[800008];
// can be used for min,max ,xor,gcd
void build(int index, int low, int high)
{
    if (low == high)
    {
        tree[index] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
}

int query(int index, int low, int high, int l, int r) // l and r is our query
// low and high is the range covered by that index
{
    if (low >= l && high <= r)
    {
        return tree[index];
    }
    if (high < l || low > r)
    {
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return min(left, right);
}

void update(int index, int low, int high, int l, int r, int v)
{
    if (low >= l && high <= r)
    {
        tree[index] = v;
        return;
    }
    if (high < l || low > r)
    {
        return;
    }
    int mid = (low + high) / 2;
    update(2 * index + 1, low, mid, l, r, v);
    update(2 * index + 2, mid + 1, high, l, r, v);
    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0, 0, n - 1); // init, 0 based indexing
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl; // we can query here in O(LogN)
    }
}