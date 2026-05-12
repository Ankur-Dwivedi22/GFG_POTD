#include <bits/stdc++.h>
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * 1ll * b;
}

class SegmentTree
{
public:
    vector<ll> tree;
    vector<int> arr;
    int n;

    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n + 1);
    }

    void buildTree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        ll mid = (start + end) / 2;

        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);

        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    void updateTree(ll node, ll start, ll end, ll ind, ll val)
    {
        if (start == end)
        {
            tree[node] = val;
            arr[ind] = val;
            return;
        }

        ll mid = (start + end) / 2;
        if (ind <= mid)
        {
            updateTree(2 * node, start, mid, ind, val);
        }
        else
        {
            updateTree(2 * node + 1, mid + 1, end, ind, val);
        }

        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (start > r || end < l)
        {
            return 1ll;
        }

        if (l <= start && end <= r)
        {
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll left = query(2 * node, start, mid, l, r);
        ll right = query(2 * node + 1, mid + 1, end, l, r);

        return lcm(left, right);
    }
};

class Solution
{
public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries)
    {
        // code here
        int n = arr.size();
        vector<ll> ans;
        SegmentTree st(arr);
        st.buildTree(1, 0, n - 1);

        for (auto &q : queries)
        {
            int type = q[0];
            if (type == 1)
            {
                ll ind = q[1];
                ll val = q[2];
                st.updateTree(1, 0, n - 1, ind, val);
            }
            else
            {
                int l = q[1];
                int r = q[2];
                ll res = st.query(1, 0, n - 1, l, r);
                ans.push_back(res);
            }
        }

        return ans;
    }
};