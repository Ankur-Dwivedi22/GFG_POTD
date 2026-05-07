/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/
// Approach : dfs
// TC : O(N * M)
// SC : O(N + M)
class Solution {
  public:
    bool dfs(Node* r1, Node* r2){
        if(!r1 && !r2){
            return true;
        }
        if(!r1 || !r2){
            return false;
        }
        
        if(r1->data == r2->data){
            return dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
        }
        return false;
    }
    
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(!root2) return true;
        if(!root1) return false;
        
        if(dfs(root1, root2)){
            return true;
        }
        
        return (isSubTree(root1->left, root2) || isSubTree(root1->right, root2));
    }
};

// Approach : String Conversion + KMP
// TC : O(N + M)
