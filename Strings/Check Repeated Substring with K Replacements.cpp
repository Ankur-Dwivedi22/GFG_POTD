class Solution
{
public:
    bool kSubstr(string &s, int k)
    {
        // code here
        if (s.size() % k != 0)
            return false;
        unordered_map<string, int> mp;
        string sub = "";
        for (int i = 0; i < s.size(); i++)
        {
            sub += s[i];
            if (sub.size() == k)
            {
                mp[sub]++;
                sub = "";
            }
        }
        if (mp.size() == 1)
        {
            return true;
        }
        if (mp.size() > 2)
        {
            return false;
        }

        int ct = 0;
        for (auto it : mp)
        {
            if (it.second >= 2)
            {
                ct++;
            }
        }

        return (ct <= 1);
    }
};