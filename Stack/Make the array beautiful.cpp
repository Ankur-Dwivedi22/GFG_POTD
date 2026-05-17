// Approach 1 : USE STACK
// TC : O(N) + O(N) + O(N)
// SC : O(N) + O(N)
class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        // code here
        int n = arr.size();
        if (n == 1)
        {
            return arr;
        }
        stack<int> st;
        if ((arr[0] >= 0 && arr[1] >= 0) || (arr[0] < 0 && arr[1] < 0))
        {
            st.push(arr[0]);
            st.push(arr[1]);
        }
        for (int i = 2; i < n; i++)
        {
            int b = arr[i];
            if (!st.empty())
            {
                int a = st.top();
                if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
                {
                    st.push(b);
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(b);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Approach 2 : Without stack
class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        // code here
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!ans.empty() && ((ans.back() >= 0 && arr[i] < 0) || (ans.back() < 0 && arr[i] >= 0)))
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};