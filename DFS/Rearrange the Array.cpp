// TC : O(N * sqrt(N))
// SC : O(N)
class Solution
{
public:
    using ll = long long;
    const ll M = 1e9 + 7;

    ll power(ll a, ll b)
    {
        ll res = 1;
        a = a % M;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                res = (res * a) % M;
            }
            a = (a * a) % M;
            b /= 2;
        }

        return res % M;
    }

    int minOperations(vector<int> &b)
    {
        // code here
        int n = b.size();
        vector<int> vis(n + 1, 0);
        vector<int> max_prime_power(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;

            int curr = i;
            int len = 0;
            while (!vis[curr])
            {
                vis[curr] = 1;
                len++;
                curr = b[curr - 1];
            }
            int temp = len;
            for (int p = 2; p * p <= temp; p++)
            {
                if (temp % p == 0)
                {
                    int ct = 0;
                    while (temp % p == 0)
                    {
                        ct++;
                        temp /= p;
                    }
                    max_prime_power[p] = max(max_prime_power[p], ct);
                }
            }
            if (temp > 1)
            {
                max_prime_power[temp] = max(max_prime_power[temp], 1);
            }
        }

        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            if (max_prime_power[i] > 0)
                ans = (ans * power(i, max_prime_power[i])) % M;
        }

        return ans;
    }
};