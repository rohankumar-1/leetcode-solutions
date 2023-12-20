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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = toBST(nums, 0, nums.size()-1);
        return root;
    }
    
    
    TreeNode *toBST(vector<int>& nums, int i, int j){
        if(i > j){
            return nullptr;
        }
        else{
            // fill curr, then recurse to both children
            int mid = i + ((j-i)/2);
            
            TreeNode *curr = new TreeNode(nums[((j-i)/2) + i]);
            curr->right = toBST(nums, mid+1, j);
            curr->left = toBST(nums, i, mid-1);
            return curr;
        }
    }
};