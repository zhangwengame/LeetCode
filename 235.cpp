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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* now=root;
        while (1) {
            if (p->val<now->val&&q->val<now->val) {
                now=now->left;
            } else if (p->val>now->val&&q->val>now->val) {
                now=now->right;                
            } else
                break;
        }
        return now;
    }
};