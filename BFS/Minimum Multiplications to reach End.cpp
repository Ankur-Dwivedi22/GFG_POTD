class Solution
{
public:
    int minSteps(vector<int> &arr, int start, int end)
    {
        // code here
        int n = arr.size();
        vector<int> vis(1000, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                int num = q.front();
                q.pop();

                if (num == end)
                {
                    return steps;
                }

                for (int m : arr)
                {
                    int val = (num * m) % 1000;
                    if (!vis[val])
                    {
                        q.push(val);
                        vis[val] = 1;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};