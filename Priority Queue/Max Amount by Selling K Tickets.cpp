// TC : O(N) + O(K * logN)
// SC : O(N)
class Solution
{
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    int maxAmount(vector<int> &arr, int k)
    {
        // code here
        priority_queue<ll> pq;
        for (int e : arr)
        {
            pq.push(e);
        }
        ll ans = 0;
        while (k > 0 && !pq.empty())
        {
            int t = pq.top();
            pq.pop();

            ans = (ans + t) % M;
            if (t - 1 > 0)
                pq.push(t - 1);
            k--;
        }

        return ans;
    }
};

// MATH + Sorting
// TC : O(N * logN)
// SC : O(1)
class Solution
{
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    ll rangeSum(ll start, ll end)
    {
        ll ct = start - end;
        ll ans = ct * (start + end + 1) / 2;
        return ans % M;
    }

    int maxAmount(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        ll ans = 0, ct = 0;

        for (int i = 0; i < n && k > 0; i++)
        {
            ct++;
            ll curr = arr[i];
            ll next_val = (i + 1 < n ? arr[i + 1] : 0);

            if (curr == next_val)
                continue;

            ll tkts = ct * (curr - next_val);
            if (k >= tkts)
            {
                ll val = (ct * rangeSum(curr, next_val)) % M;
                ans = (ans + val) % M;
                k -= tkts;
            }
            else
            {
                ll full = k / ct;
                ll rem = k % ct;

                if (full > 0)
                {
                    ll val = (ct * rangeSum(curr, curr - full)) % M;
                    ans = (ans + val) % M;
                }

                ll new_val = curr - full;
                ans = (ans + (rem * new_val) % M) % M;
                k = 0;
            }
        }

        return ans;
    }
};