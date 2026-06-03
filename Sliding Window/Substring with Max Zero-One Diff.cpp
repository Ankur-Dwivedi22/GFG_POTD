// Approach : Sliding Window
// TC : O(N)
// SC : O(1)
class Solution
{
public:
    int maxSubstring(string &s)
    {
        // code here
        int n = s.size();
        int left = 0, right = 0;
        int ct0 = 0, ct1 = 0;
        int ans = -1;
        while (right < n)
        {
            if (s[right] == '0')
                ct0++;
            else
                ct1++;

            while (left <= right && ct0 - ct1 < 0)
            {
                if (s[left] == '0')
                    ct0--;
                else
                    ct1--;
                left++;
            }
            if (ct0 != 0)
                ans = max(ans, ct0 - ct1);

            right++;
        }

        return ans;
    }
};

// Approach 2 : Kadane's Algorithm
// TC : O(N)
// SC : O(1)

class Solution
{
public:
    int maxSubstring(string &s)
    {
        // code here
        int n = s.size();
        int ans = -1, curr_diff = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                curr_diff++;
            }
            else
            {
                curr_diff--;
            }

            if (curr_diff <= 0)
            {
                curr_diff = 0;
            }
            else
            {
                ans = max(ans, curr_diff);
            }
        }

        return ans;
    }
};