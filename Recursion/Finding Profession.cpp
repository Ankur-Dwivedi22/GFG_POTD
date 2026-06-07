// Approach : Recursion
// TC : O(log(pos))
// SC : O(log(pos))
class Solution
{
public:
    string profession(int level, int pos)
    {
        // code here
        if (level == 1 || pos == 1)
        {
            return "Engineer";
        }

        string parent = profession(level - 1, (pos + 1) / 2);
        if (pos % 2 != 0)
        {
            return parent;
        }
        return (parent == "Engineer") ? "Doctor" : "Engineer";
    }
};

// Approach : Iterative
// TC : O(log(pos))
// SC : O(1)
class Solution
{
public:
    string profession(int level, int pos)
    {
        // code here
        int flips = 0;
        while (pos > 1)
        {
            if (pos % 2 == 0)
            {
                flips++;
            }
            pos = (pos + 1) / 2;
        }

        if (flips % 2 == 0)
        {
            return "Engineer";
        }

        return "Doctor";
    }
};