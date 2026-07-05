class Solution
{
public:
    int maxCharGap(string &s)
    {
        // code here
        int n = s.size();
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = -1;
        for (int i = 0; i < 26; i++)
        {
            if (pos[i].size() > 1)
            {
                ans = max(ans, pos[i].back() - pos[i][0] - 1);
            }
        }

        return ans;
    }
};

// space optimised
class Solution
{
public:
    int maxCharGap(string &s)
    {
        // code here
        int n = s.size();
        int ans = -1;
        vector<int> pos(26, -1);

        for (int i = 0; i < n; i++)
        {
            if (pos[s[i] - 'a'] == -1)
            {
                pos[s[i] - 'a'] = i;
            }
            else
            {
                ans = max(ans, i - pos[s[i] - 'a'] - 1);
            }
        }

        return ans;
    }
};