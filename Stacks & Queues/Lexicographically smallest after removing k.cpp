class Solution
{
public:
    string lexicographicallySmallest(string &s, int k)
    {
        // code here
        int n = s.size();
        if ((n & (n - 1)) == 0)
        {
            k /= 2;
        }
        else
        {
            k *= 2;
        }

        if (k >= n)
        {
            return "-1";
        }

        string ans = "";
        for (char ch : s)
        {
            while (k > 0 && !ans.empty() && ans.back() > ch)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }

        while (k > 0 && !ans.empty())
        {
            ans.pop_back();
            k--;
        }

        return (ans == "" ? "-1" : ans);
    }
};