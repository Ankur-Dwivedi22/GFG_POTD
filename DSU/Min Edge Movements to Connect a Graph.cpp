class DSU
{
public:
    int n;
    vector<int> parent, size;

    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] <= size[ulp_v])
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = parent[ulp_v];
        }
        else
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u];
        }
    }
};

class Solution
{
public:
    int minEdgesReq(int n, vector<vector<int>> &edges)
    {
        // code here
        DSU ds(n);
        int extra = 0, ct = n;
        for (auto it : edges)
        {
            int u = it[0], v = it[1];

            if (ds.find(u) == ds.find(v))
            {
                extra++;
            }
            else
            {
                ds.unionBySize(u, v);
                ct--;
            }
        }

        int ans = ct - 1;
        if (ans > extra)
        {
            return -1;
        }

        return ans;
    }
};