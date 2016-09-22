class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int> > f(n,vector<int>(m,0));
        f[n-1][m-1]=dungeon[n-1][m-1]<0?1-dungeon[n-1][m-1]:1;
        for (int i=n-1;i>=0;i--)
            for (int j=m-1;j>=0;j--) {
                if (i==n-1&&j==m-1)
                    continue;
                int a=i<n-1?f[i+1][j]:numeric_limits<int>::max();
                int b=j<m-1?f[i][j+1]:numeric_limits<int>::max();
                if (dungeon[i][j]>0)
                    f[i][j]=dungeon[i][j]-min(a,b)>=0?1:min(a,b)-dungeon[i][j];
                else
                    f[i][j]=-dungeon[i][j]+min(a,b);
            }
        return f[0][0];

    }
};