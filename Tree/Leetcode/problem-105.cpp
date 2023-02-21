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
    TreeNode *traverse(int prel,int prer, int inl, int inr,map<int,int>&m,vector<int>&preorder){
        if(prel>prer or inl>inr) return NULL;
        TreeNode *root = new TreeNode(preorder[prel]);
        int main = m[root->val];
        int left = main-inl;
        root->left = traverse(prel+1,prel+left,inl,main-1,m,preorder);
        root->right = traverse(prel+left+1,prer,main+1,inr,m,preorder);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        TreeNode *root = traverse(0,preorder.size()-1,0,inorder.size(),m,preorder);
        return root;
    }
};