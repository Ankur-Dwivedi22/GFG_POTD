class Solution
{
public:
    vector<int> left(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        int best = arr[0], curr = arr[0];
        ans[0] = best;
        for (int i = 1; i < n; i++)
        {
            curr = max(arr[i], arr[i] + curr);
            best = max(best, curr);
            ans[i] = best;
        }

        return ans;
    }

    vector<int> right(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        int best = arr[n - 1], curr = arr[n - 1];
        ans[n - 1] = best;
        for (int i = n - 2; i >= 0; i--)
        {
            curr = max(arr[i], arr[i] + curr);
            best = max(best, curr);
            ans[i] = best;
        }

        return ans;
    }

    int maxDiffSubArrays(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        vector<int> leftMax = left(arr);
        vector<int> rightMax = right(arr);

        vector<int> invArr = arr;
        for (int i = 0; i < n; i++)
        {
            invArr[i] *= -1;
        }

        vector<int> leftMin = left(invArr);
        vector<int> rightMin = right(invArr);

        for (int &x : leftMin)
        {
            x *= -1;
        }

        for (int &x : rightMin)
        {
            x *= -1;
        }

        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            int c1 = abs(leftMin[i] - rightMax[i + 1]);
            int c2 = abs(leftMax[i] - rightMin[i + 1]);
            ans = max({ans, c1, c2});
        }

        return ans;
    }
};