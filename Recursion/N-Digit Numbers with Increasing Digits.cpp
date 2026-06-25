class Solution
{
public:
    void fun(string &s, int n, vector<int> &ans)
    {
        if (s.size() == n)
        {
            int num = stoi(s);
            string check = to_string(num);
            if (check.size() != n)
                return;
            ans.push_back(num);
            return;
        }

        for (char ch = '0'; ch <= '9'; ch++)
        {
            if (s.empty() || ch > s.back())
            {
                s.push_back(ch);
                fun(s, n, ans);
                s.pop_back();
            }
        }
    }
    vector<int> increasingNumbers(int n)
    {
        // code here
        vector<int> ans;
        if (n >= 10)
        {
            return ans;
        }
        string s;
        fun(s, n, ans);

        return ans;
    }
};