// TC : O(N)
// SC : O(N)
class Solution
{
public:
    vector<int> optimalArray(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> pre(n), ans;
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int m = i / 2;
            int left = abs(pre[m] - (m + 1) * arr[m]);
            int right = abs((pre[i] - pre[m]) - (i - m) * arr[m]);
            ans.push_back(left + right);
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(1)
class Solution
{
public:
    vector<int> optimalArray(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans;
        int sum = 0, leftSum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int m = i / 2, val = 0;
            if (i % 2 == 0)
            {
                leftSum += arr[m];
                val = sum - 2 * leftSum + arr[m];
            }
            else
            {
                val = sum - 2 * leftSum;
            }

            ans.push_back(val);
        }

        return ans;
    }
};