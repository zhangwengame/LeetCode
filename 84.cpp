class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> no;
        heights.push_back(0);
        int ret=0;
        for (int i=0;i<heights.size();i++) {
            if (no.empty()||heights[i]>heights[no.top()]) {
                no.push(i);
            } else {
                while (!no.empty() && heights[i]<=heights[no.top()]) {
                    int tmp=no.top();
                    no.pop();
                    int begin=-1;
                    if (!no.empty())
                        begin=no.top();
                    ret=max(ret,heights[tmp]*(i-begin-1));    
                }
                no.push(i);
            }
        }
        return ret;
    }
};