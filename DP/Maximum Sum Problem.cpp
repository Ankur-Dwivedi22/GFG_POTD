// Approach 1 : Tabulation (Bottom Up)
// TC : O(N)
// SC : O(N)

class Solution
{
public:
    int maxSum(int n)
    {
        // code here.
        if (n <= 11)
        {
            return n;
        }
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= 11; i++)
        {
            dp[i] = i;
        }

        for (int i = 12; i <= n; i++)
        {
            dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
        }

        return dp[n];
    }
};

// Approach 2 : Memoisation (Top down)
// TC : O(logN)
// SC : O(logN)

class Solution
{
public:
    unordered_map<int, int> memo;
    int maxSum(int n)
    {
        // code here.
        if (n <= 11)
        {
            return n;
        }

        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }

        int sum = maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4);
        return memo[n] = max(n, sum);
    }
};