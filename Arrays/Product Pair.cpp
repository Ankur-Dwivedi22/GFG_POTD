// Approach 1 : Maps
// TC : O(N)
// SC : O(N)
class Solution
{
public:
    bool isProduct(vector<int> &arr, long long target)
    {
        // code here
        unordered_map<int, int> mp;
        for (int e : arr)
        {
            mp[e]++;
        }

        for (int e : arr)
        {
            if (e == 0)
            {
                if (target == 0)
                    return true;
            }
            else if (target % e == 0)
            {
                int req = target / e;
                if ((req != e && mp[req] > 0) || (req == e && mp[req] > 1))
                {
                    // cout<<e<<" "<<req<<"\n";
                    return true;
                }
            }
        }

        return false;
    }
};

// Approach 2 : Set and Single Pass
// TC : O(N)
// SC : O(N)
class Solution
{
public:
    bool isProduct(vector<int> &arr, long long target)
    {
        // code here
        if (target == 0)
        {
            for (int e : arr)
            {
                if (e == 0)
                    return true;
            }
            return false;
        }

        unordered_set<int> seen;
        seen.reserve(arr.size());

        for (int e : arr)
        {
            if (e == 0)
                continue;
            if (target % e == 0)
            {
                long long req = target / e;
                if (req >= INT_MIN && req <= INT_MAX && seen.count(req))
                {
                    return true;
                }
            }
            seen.insert(e);
        }

        return false;
    }
};

// Approach 3 : Binary Search
// TC : O(N * logN)
// SC : O(1)
class Solution
{
public:
    bool search(vector<int> &arr, int start, int target)
    {
        int lo = start, hi = arr.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target)
            {
                return true;
            }
            else if (arr[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return false;
    }

    bool isProduct(vector<int> &arr, long long target)
    {
        // code here
        if (target == 0)
        {
            for (int e : arr)
            {
                if (e == 0)
                    return true;
            }
            return false;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
                continue;
            if (target % arr[i] == 0)
            {
                long long req = target / arr[i];
                if (req > INT_MAX || req < INT_MIN)
                    continue;
                if (search(arr, i + 1, req))
                {
                    return true;
                }
            }
        }

        return false;
    }
};