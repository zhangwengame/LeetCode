class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if (n==0)
            return vector<int>();
        int m=matrix[0].size();
        if (m==0)
            return vector<int>();
        vector<int> ret;
        int x=0;
        int y=0;
        int left=0;
        int right=m-1;
        int up=0;
        int down=n-1;
        while (1) {
            for (;x<=right;x++) {
                ret.push_back(matrix[y][x]);
            }
            x--;
            y++;
            up=y;
            if (y>down)
                break;
            for (;y<=down;y++)
                ret.push_back(matrix[y][x]);
            y--;
            x--;
            if (x<left)
                break;
            right=x;
            for (;x>=left;x--)
                ret.push_back(matrix[y][x]);
            x++;
            y--;
            down=y;
            if (y<up)
                break;
            for (;y>=up;y--)
                ret.push_back(matrix[y][x]);
            y++;
            x++;
            left=x;
            if (x>right)
                break;
        }
        return ret;
    }
};