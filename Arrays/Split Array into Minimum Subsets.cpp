// TC : O(N)
// SC : O(N)
class Solution
{
public:
    int minSubsets(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> mp;
        for (int e : arr)
        {
            mp[e]++;
        }

        int ct = 0;
        for (int e : arr)
        {
            if (mp.find(e - 1) == mp.end())
            {
                ct++;
            }
        }

        return ct;
    }
};

// TC : O(N * logN)
// SC : O(1)
class Solution
{
public:
    int minSubsets(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        int ct = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != 1)
            {
                ct++;
            }
        }

        return ct;
    }
};