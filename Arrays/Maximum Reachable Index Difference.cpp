class Solution
{
public:
    int maxIndexDifference(string &s)
    {
        // code here
        int n = s.size();
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                start = i;
                break;
            }
        }

        if (start == -1)
        {
            return -1;
        }

        vector<int> seen(26, 0);
        seen[0] = 1;
        int ans = 0;
        for (int i = start; i < n; i++)
        {
            int ind = s[i] - 'a';
            if (ind - 1 >= 0 && seen[ind - 1])
            {
                ans = max(ans, i - start);
                seen[ind] = 1;
            }
        }

        return ans;
    }
};
