class Solution
{
public:
    int countWays(int n, int sum)
    {
        // code here
        vector<vector<int>> ahead(sum + 1, vector<int>(2, 0));
        vector<vector<int>> dp(sum + 1, vector<int>(2, 0));
        ahead[sum][0] = ahead[sum][1] = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int curr = 0; curr <= sum; curr++)
            {
                for (int lz = 0; lz <= 1; lz++)
                {
                    int res = 0;
                    for (int dig = 0; dig <= 9; dig++)
                    {
                        if (lz && dig == 0)
                            continue;
                        if (curr + dig > sum)
                            continue;
                        res += ahead[curr + dig][0];
                    }

                    dp[curr][lz] = res;
                }
            }
            ahead = dp;
        }
        int ans = ahead[0][1];
        return (ans == 0 ? -1 : ans);
    }
};