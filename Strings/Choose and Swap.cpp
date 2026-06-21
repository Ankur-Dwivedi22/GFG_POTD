class Solution
{
public:
    string chooseSwap(string &s)
    {
        // code here
        int n = s.size();
        vector<int> pos(26, -1);
        for (int i = 0; i < n; i++)
        {
            int ind = s[i] - 'a';
            if (pos[ind] == -1)
            {
                pos[ind] = i;
            }
        }

        char x, y;
        bool f = false;

        for (int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            for (int j = 0; j < curr; j++)
            {
                int ind = pos[j];
                if (ind > i)
                {
                    x = s[i];
                    y = char(j + 'a');
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }

        if (!f)
            return s;

        string res = s;
        for (char &c : res)
        {
            if (c == x)
            {
                c = y;
            }
            else if (c == y)
            {
                c = x;
            }
        }

        return res;
    }
};
