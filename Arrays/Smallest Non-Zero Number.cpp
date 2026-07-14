// TC : O(N * log(max_val))
// SC : O(1)
class Solution
{
public:
    bool check(vector<int> &arr, int x)
    {
        for (int e : arr)
        {
            if (x > e)
            {
                x += (x - e);
            }
            else
            {
                x -= (e - x);
            }
            if (x < 0)
                return false;
            if (x > 1e5)
                return true;
        }

        return true;
    }

    int find(vector<int> &arr)
    {
        // code here
        int lo = 0, hi = 1e5;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(arr, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(1)
class Solution
{
public:
    int find(vector<int> &arr)
    {
        // code here
        int x = 0;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            x = (x + arr[i] + 1) / 2;
        }

        return x;
    }
};