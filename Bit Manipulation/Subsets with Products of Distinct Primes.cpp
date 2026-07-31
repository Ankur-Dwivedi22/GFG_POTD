class Solution
{
public:
    using ll = long long;
    const ll M = 1e9 + 7;

    ll power(ll b, ll e)
    {
        b = (b % M);
        ll res = 1;
        while (e > 0)
        {
            if (e & 1)
                res = (res * b) % M;
            b = (b * b) % M;
            e /= 2;
        }

        return res;
    }

    int countSubsets(vector<int> &arr)
    {
        // code here
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> freq(31, 0);

        for (int e : arr)
        {
            freq[e]++;
        }

        vector<int> mask(31, 0);
        for (int i = 2; i <= 30; i++)
        {
            int temp = i;
            int m = 0;
            for (int j = 0; j < 10; j++)
            {
                int ct = 0;
                while (temp % primes[j] == 0)
                {
                    ct++;
                    temp /= primes[j];
                }

                if (ct > 1)
                {
                    m = -1;
                    break;
                }

                if (ct == 1)
                {
                    m |= (1 << j);
                }
            }
            mask[i] = m;
        }

        vector<ll> dp(1024, 0);
        dp[0] = 1;

        for (int i = 2; i <= 30; i++)
        {
            if (freq[i] == 0 || mask[i] == -1)
                continue;
            for (int j = 1023; j >= 0; j--)
            {
                if ((j & mask[i]) == 0)
                {
                    dp[j | mask[i]] = (dp[j | mask[i]] + dp[j] * freq[i]) % M;
                }
            }
        }

        ll s = 0;
        for (int i = 1; i < 1024; i++)
            s = (s + dp[i]) % M;

        ll ways1 = power(2, freq[1]);
        ll ans = ((ways1 * s) % M);

        // ans = (ans - 1 + M) % M;
        return ans;
    }
};