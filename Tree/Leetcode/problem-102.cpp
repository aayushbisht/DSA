/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector<int>> levelOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            vector<vector<int>> v;
            vector<int>cur;
            if (root == NULL) return v;
            q.push(root);
            cout<<root->val;
            q.push(NULL);


            while (!q.empty())
            {

                TreeNode *temp = q.front();
                q.pop();
                if (temp == NULL)
                {
                    v.push_back(cur);
                    cur.resize(0);
                    if (!q.empty())
                        q.push(NULL);
                }
                else
                {
                    cur.push_back(temp->val);
                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
            return v;
        }
};
 