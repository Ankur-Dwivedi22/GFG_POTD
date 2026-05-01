class Solution
{
public:
    bool isMaxHeap(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int root = arr[i];
            int left = (2 * i + 1 < n ? arr[2 * i + 1] : 0);
            int right = (2 * i + 2 < n ? arr[2 * i + 2] : 0);
            if (root < left || root < right)
            {
                return false;
            }
        }

        return true;
    }
};