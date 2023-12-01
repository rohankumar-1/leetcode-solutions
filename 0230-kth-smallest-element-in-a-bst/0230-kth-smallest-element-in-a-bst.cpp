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
    vector<int> nums;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return nums[k-1];
    }

    void dfs(TreeNode* root, int k){
        if(root == NULL || nums.size() == k){
            return;
        }
        else{
            dfs(root->left, k);
            nums.push_back(root->val);
            dfs(root->right, k);
        }
    }
};