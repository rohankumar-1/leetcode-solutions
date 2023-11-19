/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v1;
    vector<int> v2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, 0);
        dfs(root2, 1);

        if(v1.size() != v2.size()){
            return false;
        }

        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }

    void dfs(TreeNode* root, int idx){
        if(root == nullptr){
            return;
        }
        else if(root->right == nullptr && root->left == nullptr){
            // this is leaf node (no branches)
            if(idx == 0){
                v1.push_back(root->val);
            }
            else{
                v2.push_back(root->val);
            }
        }
        else{
            // not leaf node
            if(root->left){
                dfs(root->left, idx);
            }
            if(root->right){
                dfs(root->right, idx);
            }
            return;
        }
    }
};