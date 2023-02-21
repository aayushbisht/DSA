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
    TreeNode *traverse(int prel,int prer, int inl, int inr,map<int,int>&m,vector<int>&postorder){
        if(prel>prer or inl>inr) return NULL;
        TreeNode *root = new TreeNode(postorder[prer]);
        int main = m[postorder[prer]];
        int left = main-inl;
        root->left = traverse(prel,prel+left-1,inl,main-1,m,postorder);
        root->right = traverse(prel+left,prer-1,main+1,inr,m,postorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        TreeNode *root = traverse(0,postorder.size()-1,0,inorder.size(),m,postorder);
        return root;
    }
    
};