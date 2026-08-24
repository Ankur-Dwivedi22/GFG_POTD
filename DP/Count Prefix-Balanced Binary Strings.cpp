class Solution
{
public:
    const int M = 1e9 + 7;
    int prefixStrings(int n)
    {
        // code here
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            long long res = 0;
            for (int j = 0; j <= i - 1; j++)
            {
                res = (res + (dp[j] * 1ll * dp[i - 1 - j])) % M;
            }
            dp[i] = (int)res;
        }

        return dp[n];
    }
};
