class Solution
{
public:
    int maxSubsetXOR(vector<int> &arr)
    {
        // code here
        vector<int> basis(32, 0);
        for (int x : arr)
        {
            for (int i = 31; i >= 0; i--)
            {
                int bit = (x >> i) & 1;
                if (bit == 1)
                {
                    if (basis[i] == 0)
                    {
                        basis[i] = x;
                        break;
                    }
                    else
                    {
                        x = x ^ basis[i];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (basis[i] == 0)
                continue;
            if ((ans ^ basis[i]) > ans)
                ans = (ans ^ basis[i]);
        }

        return ans;
    }
};