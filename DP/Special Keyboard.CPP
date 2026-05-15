class Solution
{
public:
    int optimalKeys(int n)
    {
        // code here
        if (n <= 6)
            return n;

        vector<int> dp(n + 1);

        // Base cases
        for (int i = 0; i <= 6; i++)
            dp[i] = i;

        for (int i = 7; i <= n; i++)
        {

            // Option 1: press A
            dp[i] = dp[i - 1] + 1;

            // Option 2:
            // choose breakpoint j
            for (int j = 1; j <= i - 3; j++)
            {

                dp[i] = max(dp[i],
                            dp[j] * (i - j - 1));
            }
        }

        return dp[n];
    }
};