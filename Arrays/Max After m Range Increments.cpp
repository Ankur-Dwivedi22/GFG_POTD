class Solution
{
public:
    int findMax(int n, vector<int> &a, vector<int> &b, vector<int> &k)
    {
        // code here
        vector<int> arr(n, 0);
        for (int i = 0; i < a.size(); i++)
        {
            int l = a[i], r = b[i] + 1, v = k[i];
            arr[l] += v;
            if (r < n)
                arr[r] -= v;
        }

        int ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
            ans = max(ans, arr[i]);
        }

        // for(int i=0; i<n; i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";

        return ans;
    }
};