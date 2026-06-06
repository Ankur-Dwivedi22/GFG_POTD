// TC : O(N * M)
// SC : O(1)
class Solution
{
public:
    vector<vector<int>> v = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    int solve(int r, int c, int n, int m)
    {
        int ct = 0;
        for (int i = 0; i < 8; i++)
        {
            int nr = r + v[i][0];
            int nc = c + v[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                ct++;
            }
        }

        return n * m - ct - 1;
    }

    int numOfWays(int n, int m)
    {
        // code here
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += solve(i, j, n, m);
            }
        }

        return ans;
    }
};

// TC : O(1)
// SC : O(1)
class Solution
{
public:
    int numOfWays(int n, int m)
    {
        // code here
        int totalCells = n * m;
        int totalWays = totalCells * (totalCells - 1);

        int attackCells = 0;

        if (n >= 1 && m >= 2)
        {
            attackCells += 4 * (n - 1) * (m - 2);
        }

        if (n >= 2 && m >= 1)
        {
            attackCells += 4 * (n - 2) * (m - 1);
        }

        return totalWays - attackCells;
    }
};