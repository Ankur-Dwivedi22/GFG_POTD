class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        // code here
        int ct1 = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                ct1++;
        }

        if (ct1 == 0)
        {
            return -1;
        }
        int l = 0, ct0 = 0;
        int swaps = n;
        for (int r = 0; r < n; r++)
        {
            if (arr[r] == 0)
                ct0++;
            if (r - l + 1 > ct1)
            {
                if (arr[l] == 0)
                    ct0--;
                l++;
            }
            if (r - l + 1 == ct1)
            {
                // cout<<ct0<<"\n";
                swaps = min(swaps, ct0);
            }
        }

        return swaps;
    }
};