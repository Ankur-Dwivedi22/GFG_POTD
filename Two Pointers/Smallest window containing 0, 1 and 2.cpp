class Solution
{
public:
    int smallestSubstring(string s)
    {
        // code here
        int lastOne = -1, lastTwo = -1, lastZero = -1;
        int ans = 1e9;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                lastZero = i;
            else if (s[i] == '1')
                lastOne = i;
            else
                lastTwo = i;

            if (lastZero != -1 && lastOne != -1 && lastTwo != -1)
            {
                int start = min({lastOne, lastZero, lastTwo});
                ans = min(ans, i - start + 1);
            }
        }

        ans = (ans == 1e9 ? -1 : ans);
        return ans;
    }
};
