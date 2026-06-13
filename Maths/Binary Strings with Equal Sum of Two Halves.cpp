class Solution
{
public:
    using ll = long long;
    const int M = 1e9 + 7;

    ll power(ll b, ll e)
    {
        b = (b % M);
        ll ans = 1;
        while (e > 0)
        {
            if (e % 2 == 1)
                ans = (ans * b) % M;
            b = (b * b) % M;
            e /= 2;
        }

        return ans;
    }

    ll modInv(ll n)
    {
        return power(n, M - 2);
    }

    int computeValue(int n)
    {
        // code here
        ll num = 1, den = 1;
        for (ll i = 1; i <= n; i++)
        {
            num = (num * (2ll * n - i + 1)) % M;
            den = (den * i) % M;
        }

        ll ans = (num * modInv(den)) % M;
        return ans;
    }
};