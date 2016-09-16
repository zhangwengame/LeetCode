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
        heights.pop_back();
        return ret;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()==0||matrix[0].size()==0)
            return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> up(m,0);
        int ret=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (matrix[i][j]=='1') {
                    up[j]=up[j]+1;
                } else 
                    up[j]=0;
            }
            ret=max(ret,largestRectangleArea(up));
        }
        return ret;
    }
};