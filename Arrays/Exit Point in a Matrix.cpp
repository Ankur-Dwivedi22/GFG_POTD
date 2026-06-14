class Solution
{
public:
    vector<int> exitPoint(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int k = 0;
        int r = 0, c = 0;
        vector<int> ans;
        while (r >= 0 && r < n && c >= 0 && c < m)
        {
            // cout<<r<<" "<<c<<"\n";
            ans = {r, c};
            if (mat[r][c] == 1)
            {
                k = (k + 1) % 4;
                mat[r][c] = 0;
            }
            r = r + dirs[k][0];
            c = c + dirs[k][1];
        }

        return ans;
    }
};