class Solution
{
public:
    int maximumSum(vector<vector<int>> &mat, int k)
    {
        // code here
        int n = mat.size(), ans = INT_MIN;
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            pre[i][1] = pre[i - 1][1] + mat[i - 1][0];
            pre[1][i] = pre[1][i - 1] + mat[0][i - 1];
        }

        for (int r = 2; r <= n; r++)
        {
            for (int c = 2; c <= n; c++)
            {
                pre[r][c] = pre[r - 1][c] + pre[r][c - 1] - pre[r - 1][c - 1] + mat[r - 1][c - 1];
            }
        }

        // for(int r=0; r<=n; r++){
        //     for(int c=0; c<=n; c++){
        //         cout<<pre[r][c]<<" ";
        //     }
        //     cout<<"\n";
        // }

        for (int r = 1; r <= n - k + 1; r++)
        {
            for (int c = 1; c <= n - k + 1; c++)
            {
                int i = r + k - 1;
                int j = c + k - 1;
                int sum = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[r - 1][c - 1];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// O(N * N)
// O(N)
class Solution
{
public:
    int maximumSum(vector<vector<int>> &mat, int k)
    {
        // code here
        int n = mat.size(), ans = INT_MIN;
        vector<int> colsum(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                colsum[j] += mat[i][j];
                if (i >= k)
                {
                    colsum[j] -= mat[i - k][j];
                }
            }

            if (i >= k - 1)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += colsum[j];
                    if (j >= k)
                    {
                        sum -= colsum[j - k];
                    }
                    if (j >= k - 1)
                    {
                        ans = max(sum, ans);
                    }
                }
            }
        }

        return ans;
    }
};
