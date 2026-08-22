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
}; */

class Solution {
  public:
    map<int, vector<pair<int, int>>> mp;
    map<int,int> vis;
    void createMap(Node* node){
        if(node == NULL) return; 
        if(node->left != NULL){
            mp[node->data].push_back({node->left->data, 0});
            mp[node->left->data].push_back({node->data, 0});
            createMap(node->left);
        }
        
        if(node->right != NULL){
            mp[node->data].push_back({node->right->data, 1});
            mp[node->right->data].push_back({node->data, 1});
            createMap(node->right);
        }
        
    }
    
    int count(int node, int dir, int q){
        vis[node] = 1;
        if(node == q) return 0;
        int ans = INT_MAX;
        for(auto it : mp[node]){
            if(vis.find(it.first) == vis.end()){
                int x = count(it.first, it.second, q);
                if(x != INT_MAX){
                    int turn = (dir != -1 && dir != it.second);
                    ans = min(ans, turn + x);
                }
            }
        }
        vis.erase(node);
        return ans;
    }
    
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        mp.clear();
        vis.clear();
        createMap(root);
        // vis[p] = 1;
        int ans = count(p, -1, q);
        return ((ans == INT_MAX || ans == 0) ? -1 : ans);
    }
};