// TC : O(N)
// SC : O(N)
class Solution
{
public:
    int bitonic(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> pre(n, 1), suff(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= arr[i - 1])
            {
                pre[i] = pre[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[i + 1])
            {
                suff[i] = suff[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, pre[i] + suff[i] - 1);
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(1)
class Solution
{
public:
    int bitonic(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int j = 0, mxlen = 1, start = 0, nextStart = 0;
        while (j + 1 < n)
        {
            if (arr[j] <= arr[j + 1])
                j++;
            else
            {
                while (j + 1 < n && arr[j] >= arr[j + 1])
                {
                    if (arr[j] > arr[j + 1])
                        nextStart = j + 1;
                    j++;
                }
            }
            mxlen = max(mxlen, j - start + 1);
            start = nextStart;
        }

        return mxlen;
    }
};