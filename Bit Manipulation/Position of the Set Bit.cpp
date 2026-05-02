// First Approach
// TC : O(log(n)) -> O(1) since n is 32 bit integer only
// SC : O(1)

class Solution
{
public:
    int findPosition(int n)
    {
        // code here
        int pos = -1, ct = 1;
        while (n > 0)
        {
            int dig = n % 2;
            if (dig == 1)
            {
                if (pos == -1)
                {
                    pos = ct;
                }
                else
                {
                    return -1;
                }
            }
            n /= 2;
            ct++;
        }

        return pos;
    }
};

// Second Approach
// TC : O(1)
// SC : O(1)

class Solution
{
public:
    int findPosition(int n)
    {
        // code here
        if (n & (n - 1))
        {
            return -1;
        }

        return __builtin_popcount(n - 1) + 1;
    }
};

// Implementation of buitin pop count:
// Approach 1
// TC : O(log(n))
int builtin_pop_count(int n)
{
    int ct = 0;
    while (n > 0)
    {
        ct += (n & 1);
        n >>= 1;
    }
    return ct;
}

// Approach2 (Brian Kernighan's Algorithm)
// TC : O(k) where k = number of set bits in n

int builtin_popcount(int n)
{
    int ct = 0;
    while (n > 0)
    {
        n &= (n - 1); // Clears lowest set bit
        ct++;
    }
    return ct;
}
