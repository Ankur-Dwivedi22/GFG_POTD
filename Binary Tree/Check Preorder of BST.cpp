class Solution
{
public:
    void find(int &ind, int mn, int mx, vector<int> &arr)
    {
        if (ind == arr.size())
        {
            return;
        }

        if (!(arr[ind] >= mn && arr[ind] <= mx))
        {
            return;
        }
        int val = arr[ind];
        ind++;
        find(ind, mn, val, arr);
        find(ind, val, mx, arr);
    }

    bool canRepresentBST(vector<int> &arr)
    {
        // code here
        int ind = 0;
        find(ind, -1e9, 1e9, arr);
        return ind == arr.size();
    }
};