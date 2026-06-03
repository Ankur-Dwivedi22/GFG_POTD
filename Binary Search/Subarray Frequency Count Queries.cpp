// Approach : Binary Search
// TC : O(N + Q * logN)
// SC : O(N)
class Solution
{
public:
    vector<int> freqInRange(vector<int> &a, vector<vector<int>> &queries)
    {
        // code here
        int n = a.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]].push_back(i);
        }

        for (auto q : queries)
        {
            int l = q[0], r = q[1], x = q[2];
            if (mp.find(x) != mp.end())
            {
                const vector<int> &v = mp[x];
                auto r_ind = upper_bound(v.begin(), v.end(), r);
                auto l_ind = upper_bound(v.begin(), v.end(), l - 1);
                int ct = r_ind - l_ind;
                ans.push_back(ct);
            }
            else
            {
                ans.push_back(0);
            }
        }

        return ans;
    }
};