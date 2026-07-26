class Solution
{
public:
    vector<vector<int>> levelSort(vector<int> &arr)
    {
        // code here
        vector<vector<int>> ans;
        int len = 1, idx = 0;
        while (idx < arr.size())
        {
            int ct = len;
            vector<int> temp;
            while (ct-- && idx < arr.size())
            {
                temp.push_back(arr[idx]);
                idx++;
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            len += len;
        }

        return ans;
    }
};
