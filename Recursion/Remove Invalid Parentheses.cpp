class Solution
{
public:
    bool valid(string &s, int &c1, int &c2)
    {
        for (char ch : s)
        {
            if (ch == '(')
            {
                c1++;
            }
            else if (ch == ')')
            {
                if (c1 > 0)
                {
                    c1--;
                }
                else
                {
                    c2++;
                }
            }
        }

        return (c1 == 0 && c2 == 0);
    }

    void func(int ind, string val, string &s, vector<string> &temp, int c1, int c2)
    {
        if (ind == s.size())
        {
            if (c1 > 0 || c2 > 0)
                return;
            int a = 0, b = 0;
            if (valid(val, a, b))
            {
                temp.push_back(val);
            }
            return;
        }

        if (c1 != 0 && s[ind] == '(')
        {
            func(ind + 1, val, s, temp, c1 - 1, c2);
        }

        if (c2 != 0 && s[ind] == ')')
        {
            func(ind + 1, val, s, temp, c1, c2 - 1);
        }

        func(ind + 1, val + s[ind], s, temp, c1, c2);
    }

    vector<string> validParenthesis(string &s)
    {
        // code here
        int c1 = 0, c2 = 0;
        if (valid(s, c1, c2))
        {
            return {s};
        }

        vector<string> temp, ans;
        func(0, "", s, temp, c1, c2);
        sort(temp.begin(), temp.end());

        for (string it : temp)
        {
            if (ans.empty() || ans.back() != it)
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};
