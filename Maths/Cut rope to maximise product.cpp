// TC : O(logN)
// SC : O(1)
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
    int maxProduct(int n)
    {
        // code here
        if (n == 2 || n == 3)
        {
            return n - 1;
        }
        int ct3 = n / 3;
        int rem = n % 3;

        if (rem == 1)
        {
            ct3 -= 1;
            rem = 4;
        }
        int pro = power(3, ct3);
        if (rem == 2 || rem == 4)
        {
            pro *= rem;
        }

        return pro;
    }
};