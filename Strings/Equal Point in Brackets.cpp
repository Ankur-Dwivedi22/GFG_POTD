// Approach : Simulation
// TC : O(N)
// SC: O(1)
class Solution
{
public:
    int findIndex(string &s)
    {
        // code here
        int openCt = 0, closeCt = 0;
        for (char c : s)
        {
            if (c == '(')
                openCt++;
            else if (c == ')')
                closeCt++;
        }

        int currOpen = 0, currClose = 0;
        if (currOpen == closeCt)
        {
            return 0;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                currOpen++;
            else
                currClose++;
            if (currOpen == (closeCt - currClose))
            {
                return i + 1;
            }
        }

        return -1;
    }
};

// Approach 2 : Observation
// o_left = open bracket before k
// o_right = open bracket from k
// c_left = close bracket before k
// c_right = close bracket from k

// o_left = c_right -> needed for k
// Also,
//  o_left + c_left = k
//  c_right + c_left = k => total_c = k
// TC : O(N)
// SC : O(1)
class Solution
{
public:
    int findIndex(string &s)
    {
        // code here
        int closeCt = 0;
        for (char c : s)
        {
            if (c == ')')
            {
                closeCt++;
            }
        }

        return closeCt;
    }
};