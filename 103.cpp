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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> treeQueue;
        vector<vector<int> >ret;
        if (!root)
            return ret;
        treeQueue.push(root);
        bool left2right=true;
        while (!treeQueue.empty()){
            int size=treeQueue.size();
            vector<int> currentLevel(size);
            for (int i=0;i<size;i++) {
                TreeNode* now=treeQueue.front();
                treeQueue.pop();
                if (left2right)
                    currentLevel[i]=now->val;
                else
                    currentLevel[size-1-i]=now->val;
                if (now->left)
                    treeQueue.push(now->left);
                if (now->right)
                    treeQueue.push(now->right);    
            }
            ret.push_back(currentLevel);
            left2right=!left2right;
        }
        return ret;
    }
};