// Approach : Sliding Window
// TC : O(N)
// SC : O(1)

class Solution
{
public:
    int getCount(int n)
    {
        // code here
        if (n == 1 || n == 2)
        {
            return 0;
        }

        int ct = 0;
        int sum = 0, left = -1, right = -1;
        if (n % 2 == 0)
        {
            sum += (n / 2);
            sum += (n / 2) - 1;
            left = (n / 2) - 2;
            right = (n / 2);
        }
        else
        {
            sum += (n / 2);
            sum += (n / 2) + 1;
            left = (n / 2) - 1;
            right = (n / 2) + 1;
        }

        while (left > 0)
        {
            if (sum == n)
                ct++;
            if (sum <= n)
            {
                sum += left;
                left--;
            }
            else
            {
                sum -= right;
                right--;
            }
        }

        if (sum == n)
            ct++;

        return ct;
    }
};

// Approach : Maths
// TC : O(sqrt(N))
// SC : O(1)

class Solution
{
public:
    int getCount(int n)
    {
        // code here
        int ans = 0;
        for (int k = 2; k * (k - 1) / 2 < n; k++)
        {
            int num = n - (k * (k - 1) / 2);
            if (num % k == 0)
            {
                ans++;
            }
        }

        return ans;
    }
};