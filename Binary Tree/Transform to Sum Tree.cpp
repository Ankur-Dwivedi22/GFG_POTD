/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

// Traversal (dfs)
// TC : O(N) - N is no. of nodes
// SC : O(N) - recursive stack space
class Solution
{
public:
    int updateTree(Node *node)
    {
        if (!node)
        {
            return 0;
        }

        int left = updateTree(node->left);
        int right = updateTree(node->right);
        int node_val = node->data;

        node->data = left + right;

        return (node_val + left + right);
    }

    void toSumTree(Node *root)
    {
        // code here
        updateTree(root);
    }
};