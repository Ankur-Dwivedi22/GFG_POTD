// TC : O(1)
// SC : O(1)
class Solution
{
public:
    bool isSumOfConsecutive(int n)
    {
        // code here
        return (n >= 3 && (n & (n - 1)) != 0);
    }
};