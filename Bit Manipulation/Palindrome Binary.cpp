class Solution
{
public:
    bool isBinaryPalindrome(int n)
    {
        // code here
        string s = "";
        while (n > 0)
        {
            s += (n % 2) + '0';
            n /= 2;
        }

        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};