class Solution
{
public:
    int dp[1000][1000];
    int dp_func(int i, int j, vector<int> &a, vector<int> &b)
    {
        if (j == b.size())
        {
            return 0;
        }
        if (i == a.size())
        {
            return -1e9;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int c1 = a[i] * b[j] + dp_func(i + 1, j + 1, a, b);
        int c2 = 0 + dp_func(i + 1, j, a, b);

        return dp[i][j] = max(c1, c2);
    }

    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return dp_func(0, 0, a, b);
    }
};
class Solution
{
public:
    int dp[1000][1000];
    int dp_func(int i, int j, vector<int> &a, vector<int> &b)
    {
        if (j == b.size())
        {
            return 0;
        }
        if (i == a.size())
        {
            return -1e9;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int c1 = a[i] * b[j] + dp_func(i + 1, j + 1, a, b);
        int c2 = 0 + dp_func(i + 1, j, a, b);

        return dp[i][j] = max(c1, c2);
    }

    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return dp_func(0, 0, a, b);
    }
};