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
    struct minmax{
        int min;
        int max;
        minmax():min(numeric_limits<int>::max()),max(numeric_limits<int>::min()){}
        minmax(int _min,int _max):min(_min), max(_max){}
    };
    bool checkBST(TreeNode* root, minmax &m) {
        m.min=m.max=root->val;
        minmax l;
        minmax r;
        bool lb=true;
        bool rb=true;
        if (root->left)
            lb=checkBST(root->left,l);
        if (root->right)
            rb=checkBST(root->right,r);
        if (!lb||!rb)
            return false;
        if (root->left&&l.max>=root->val||root->right&&r.min<=root->val)
            return false;
        m.min=(l.min<root->val)?l.min:root->val;
        m.max=(r.max>root->val)?r.max:root->val;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        minmax dumy;
        return checkBST(root,dumy);
    }
};