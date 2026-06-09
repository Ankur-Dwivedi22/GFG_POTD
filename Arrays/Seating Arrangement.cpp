class Solution
{
public:
    bool canSeatAllPeople(int k, vector<int> &seats)
    {
        // code here
        int n = seats.size();
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 0)
            {
                if ((i - 1 >= 0 && seats[i - 1]))
                {
                    // cout<<i<<"\n";
                    continue;
                }
                if ((i + 1 < n && seats[i + 1]))
                {
                    // cout<<i<<"\n";
                    continue;
                }
                ct++;
                seats[i] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
            {
                if (i - 1 >= 0 && seats[i - 1])
                {
                    return false;
                }
                if (i + 1 < n && seats[i + 1])
                {
                    return false;
                }
            }
        }
        // cout<<ct<<"\n";
        return (ct >= k);
    }
};