class Solution
{
public:
    int power(int b, int e)
    {
        int res = 1;
        while (e > 0)
        {
            if (e % 2 == 1)
                res = res * b;
            b = b * b;
            e /= 2;
        }

        return res;
    }

    int getLastDigit(string &a, string &b)
    {
        // code here
        if (b == "0")
        {
            return 1;
        }
        int dig = a.back() - '0';
        if (dig == 0 || dig == 1)
        {
            return dig;
        }
        int m = 1, temp = dig;
        while (1)
        {
            temp = temp * dig;
            if (temp % 10 == dig)
            {
                break;
            }
            m++;
        }

        int rem = 0;
        for (char c : b)
        {
            int val = c - '0';
            rem = ((rem * 10) + val) % m;
        }

        if (rem == 0)
            rem = m;

        return (power(dig, rem) % 10);
    }
};