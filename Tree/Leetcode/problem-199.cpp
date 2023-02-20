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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        traverse(root,0,ans);
        return ans;
    }
    void traverse(TreeNode *root, int lev, vector<int>&ans){
        if(root==NULL) return ;
        if(ans.size()==lev) ans.push_back(root->val);
        traverse(root->right,lev+1,ans);
        traverse(root->left,lev+1,ans);
    }
};