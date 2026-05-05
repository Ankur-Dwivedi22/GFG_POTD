class Solution
{
public:
    long long sumXOR(vector<int> &arr)
    {
        // code here
        long long ans = 0;
        int n = arr.size();
        for (int i = 31; i >= 0; i--)
        {
            long long ones = 0;
            for (int num : arr)
            {
                int bit = (num >> i) & 1;
                if (bit == 1)
                {
                    ones++;
                }
            }
            long long zeros = n - ones;
            ans += (zeros * ones) * (1LL << i);
        }

        return ans;
    }
};