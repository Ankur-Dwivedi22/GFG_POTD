class Solution
{
public:
    int minimumCost(vector<int> &cost, int w)
    {
        // code here
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int wt = 0; wt <= w; wt++)
        {
            dp[n][wt] = 1e9;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int wt = 1; wt <= w; wt++)
            {
                int notPick = 0 + dp[ind + 1][wt];
                int pick = 1e9;
                if (cost[ind] != -1 && (ind + 1) <= wt)
                {
                    pick = cost[ind] + dp[ind][wt - (ind + 1)];
                }

                dp[ind][wt] = min(pick, notPick);
            }
        }
        int ans = dp[0][w];
        return (ans >= 1e9 ? -1 : ans);
    }
};