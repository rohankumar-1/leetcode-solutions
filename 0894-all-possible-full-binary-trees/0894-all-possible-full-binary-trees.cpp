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

/*
Start with a binary tree made of n nodes s.t. only left node gets children

Even numbers of n do not work

We just need to keep track of # of nodes total.

Base case is a single node.

*/
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        // base case 0
        if(n % 2 == 0){
            return {};
        }
        
        // base case 1
        if(n == 1){
            return {new TreeNode()};
        }
        
        // DP case
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        
        // create current subset (we have not seen this n before)
        vector<TreeNode*> subset;

        // there are n-1 ways to split n-1 values
        for(int i = 0; i < n-1; i++){
            vector<TreeNode*> left = allPossibleFBT(i);         // all left possibilites
            vector<TreeNode*> right = allPossibleFBT(n-i-1);    // all right possibilites
            
            // iterate through all possible combinations of left and right possibilities
            for(auto l : left){
                for(auto r : right){
                    TreeNode *root = new TreeNode();    // head
            
                    root->right = r;
                    root->left = l;
                    
                    // add to subset
                    subset.push_back(root);
                }
            }
        }
        
        // fill in DP hashmap
        dp[n] = subset;
        
        return subset;
    }
};