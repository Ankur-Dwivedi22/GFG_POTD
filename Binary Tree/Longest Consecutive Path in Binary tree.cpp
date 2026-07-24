/* Structure of Binary Tree Node
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
class Solution {
  public:
    int ans = 0;
    void dfs(Node* node, int val, int len){
        ans = max(ans, len);
        if(!node){
            return;
        }
        
        if(node->data == val){
            dfs(node->left, node->data+1, 1 + len);
            dfs(node->right, node->data+1, 1 + len);
        }
        else{
            dfs(node->left, node->data+1, 1);
            dfs(node->right, node->data+1, 1);
        }
    }
    
    int longestConsecutive(Node* root) {
        // code here
        dfs(root, root->data, 0);
        ans = (ans == 1 ? -1 : ans);
        return ans;
    }
};