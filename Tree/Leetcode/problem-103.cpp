/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            int flag = true;
            vector<vector < int>> ans;
            if(root==NULL)
                return ans;
            q.push(root);
            while (!q.empty())
            {

                int size = q.size();
                vector<int> cur(size);
                for (int i = 0; i < size; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    int index = flag ? i : size - i - 1;
                    cur[index] = temp->val;
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
                flag = !flag;
                ans.push_back(cur);
            }
            return ans;
        }
};