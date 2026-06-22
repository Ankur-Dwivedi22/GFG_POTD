class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // code here
        int i = 0, j = height.size() - 1;
        long long ans = 0;
        while (i != j)
        {
            int h = min(height[i], height[j]);
            int w = j - i - 1;
            ans = max(ans, h * 1ll * w);
            if (height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return ans;
    }
};