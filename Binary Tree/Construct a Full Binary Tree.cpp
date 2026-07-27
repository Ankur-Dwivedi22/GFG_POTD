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

class Solution {
  public:
    Node* create(int &preInd, int left, int right, int n, vector<int> &pre, vector<int> &preMirror, unordered_map<int,int> &mp){
        if(preInd == n || left > right){
            return NULL;
        }    
        
        Node* root = new Node(pre[preInd++]);
        int mirrorInd = mp[pre[preInd]];
        
        if(mirrorInd >= left && mirrorInd <= right){
            root->left = create(preInd, mirrorInd, right, n, pre, preMirror, mp);
            root->right = create(preInd, left, mirrorInd-1, n, pre, preMirror, mp);
        }
        
        return root;
    }
    
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        int n = pre.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[preMirror[i]] = i;
        }
        int preInd = 0;
        return create(preInd, 0, n-1, n, pre, preMirror, mp);
    }
};