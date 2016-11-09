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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int>> lines;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ret;
        q.push(make_pair(root,0));
        while (!q.empty()) {
            auto now=q.front();
            q.pop();
            if (now.first==nullptr) 
                continue;
            lines[now.second].push_back(now.first->val);
            q.push(make_pair(now.first->left,now.second-1));
            q.push(make_pair(now.first->right,now.second+1));
            
        }
        for (auto ite=lines.begin();ite!=lines.end();ite++) {
            ret.push_back((*ite).second);
        }
        return ret;
    }
};