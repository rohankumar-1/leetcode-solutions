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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        int level = 0;
        res.push_back({});
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            
            if(curr == NULL){
                // hit dummy node
                if(q.size() > 0){
                    res.push_back({});
                    level++;
                    q.push(NULL);
                }
            }
            else{
                if(curr->left){ q.push(curr->left); }
                if(curr->right){ q.push(curr->right); }

                cout << curr->val << endl;
                res[level].push_back(curr->val);
            }
        }

        return res;
    }
};