class Solution
{
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
            {
                continue;
            }
            if (grid[nr][nc] && !vis[nr][nc])
            {
                dfs(nr, nc, grid, vis);
            }
        }
    }

    int cntOnes(vector<vector<int>> &grid)
    {
        // code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // first and last row
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j])
                dfs(0, j, grid, vis);
            if (grid[n - 1][j])
                dfs(n - 1, j, grid, vis);
        }

        // first and last col
        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][0])
                dfs(i, 0, grid, vis);
            if (grid[i][m - 1])
                dfs(i, m - 1, grid, vis);
        }

        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !vis[i][j])
                    ct++;
            }
        }

        return ct;
    }
};