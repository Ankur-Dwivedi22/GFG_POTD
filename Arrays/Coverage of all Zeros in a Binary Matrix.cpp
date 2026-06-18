class Solution
{
public:
    int findCoverage(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size(), m = mat[0].size();
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (mat[k][j] == 1)
                        {
                            ct++;
                            break;
                        }
                    }

                    for (int k = i + 1; k < n; k++)
                    {
                        if (mat[k][j] == 1)
                        {
                            ct++;
                            break;
                        }
                    }

                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (mat[i][k] == 1)
                        {
                            ct++;
                            break;
                        }
                    }

                    for (int k = j + 1; k < m; k++)
                    {
                        if (mat[i][k] == 1)
                        {
                            ct++;
                            break;
                        }
                    }
                }
            }
        }

        return ct;
    }
};
