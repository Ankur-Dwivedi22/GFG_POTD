/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int dfs(Node* node){
        if(!node){
            return 0;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        return 1 + left + right;
    }
    
    int getSize(Node* root) {
        // code here
        return dfs(root);
    }
};