/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (target>root->val) {
            if (root->right==nullptr)
                return root->val;
            int recur=closestValue(root->right,target);
            if (fabs(root->val-target)<fabs(recur-target))
                return root->val;
            else
                return recur;
        } else {
            if (root->left==nullptr)
                return root->val;
            int recur=closestValue(root->left,target);
            if (fabs(root->val-target)<fabs(recur-target))
                return root->val;
            else
                return recur;
        }
    }
};