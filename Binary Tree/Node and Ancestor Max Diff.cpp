/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
public:
    void dfs(int maxPar, Node *node, int &ans)
    {
        if (!node)
        {
            return;
        }

        if (maxPar != -1)
            ans = max(ans, maxPar - node->data);
        dfs(max(maxPar, node->data), node->left, ans);
        dfs(max(maxPar, node->data), node->right, ans);
    }

    int maxDiff(Node *root)
    {
        // code here
        int ans = INT_MIN;
        dfs(-1, root, ans);
        return ans;
    }
};