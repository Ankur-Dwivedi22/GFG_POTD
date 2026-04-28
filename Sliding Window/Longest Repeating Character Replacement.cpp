class Solution
{
public:
    int longestSubstr(string &s, int k)
    {
        // code here
        int l = 0, r = 0;
        int ans = 0, mxfreq = 0;
        vector<int> freq(26, 0);

        for (r = 0; r < s.size(); r++)
        {
            int ind = s[r] - 'A';
            freq[ind]++;

            mxfreq = max(mxfreq, freq[ind]);

            while ((r - l + 1) - mxfreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};