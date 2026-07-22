class Solution
{
public:
    int findLIS(vector<int> &arr)
    {
        vector<int> temp;
        for (int e : arr)
        {
            if (temp.empty() || (temp.back() < e))
                temp.push_back(e);
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), e) - temp.begin();
                temp[ind] = e;
            }
        }

        return temp.size();
    }

    int minDeletions(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        return n - findLIS(arr);
    }
};