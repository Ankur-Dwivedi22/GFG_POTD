// Approach 1 : Binary Search
// TC : O( N * logN)
// SC : O(1)
class Solution
{
public:
    int binarySearchable(vector<int> &arr)
    {
        // code here
        int ct = 0;
        for (int e : arr)
        {
            int lo = 0, hi = arr.size() - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] == e)
                {
                    ct++;
                    break;
                }
                else if (arr[mid] < e)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }

        return ct;
    }
};

// Approach 2 : DFS
// TC : O(N)
// SC : O(logN)
class Solution
{
public:
    int dfs(int lo, int hi, vector<int> &arr, int mn, int mx)
    {
        if (lo > hi)
        {
            return 0;
        }

        int mid = lo + (hi - lo) / 2;
        int ct = 0;
        if (mn <= arr[mid] && arr[mid] <= mx)
        {
            ct = 1;
        }

        ct += dfs(lo, mid - 1, arr, mn, min(mx, arr[mid]));
        ct += dfs(mid + 1, hi, arr, max(mn, arr[mid]), mx);

        return ct;
    }

    int binarySearchable(vector<int> &arr)
    {
        // code here
        return dfs(0, arr.size() - 1, arr, INT_MIN, INT_MAX);
    }
};