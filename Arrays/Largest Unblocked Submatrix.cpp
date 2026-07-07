class Solution
{
public:
    int largestArea(int n, int m, vector<vector<int>> &arr)
    {
        // code here
        vector<int> rows, cols;
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);

        for (auto it : arr)
        {
            int r = it[0], c = it[1];
            rows.push_back(r);
            cols.push_back(c);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int height = 0, width = 0;
        for (int i = 1; i < rows.size(); i++)
        {
            height = max(height, rows[i] - rows[i - 1] - 1);
            width = max(width, cols[i] - cols[i - 1] - 1);
        }

        return height * width;
    }
};