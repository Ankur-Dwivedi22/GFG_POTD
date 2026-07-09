class Solution
{
public:
    int countKdivPairs(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> mp;
        for (int e : arr)
        {
            mp[e % k]++;
        }

        int ans = (mp[0] * (mp[0] - 1)) / 2;
        int i = 1, j = k - 1;
        while (i < j)
        {
            ans += mp[i] * mp[j];
            i++;
            j--;
        }

        if (i == j)
            ans += (mp[i] * (mp[i] - 1) / 2);
        return ans;
    }
};