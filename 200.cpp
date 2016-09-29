class Solution {
public:
    void floodFill(int y,int x,vector<vector<bool> >& flag, vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int> > q;
        flag[y][x]=true;
        q.push(make_pair(y,x));
        while (!q.empty()) {
            pair<int,int> now=q.front();
            q.pop();
            if (now.first>0&&!flag[now.first-1][now.second]&&grid[now.first-1][now.second]=='1') {
                flag[now.first-1][now.second]=true;
                q.push(make_pair(now.first-1,now.second));
            }
            if (now.first<n-1&&!flag[now.first+1][now.second]&&grid[now.first+1][now.second]=='1') {
                flag[now.first+1][now.second]=true;
                q.push(make_pair(now.first+1,now.second));
            }
            if (now.second>0&&!flag[now.first][now.second-1]&&grid[now.first][now.second-1]=='1') {
                flag[now.first][now.second-1]=true;
                q.push(make_pair(now.first,now.second-1));
            }
            if (now.second<m-1&&!flag[now.first][now.second+1]&&grid[now.first][now.second+1]=='1') {
                flag[now.first][now.second+1]=true;
                q.push(make_pair(now.first,now.second+1));
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if (n==0)
            return 0;
        int m=grid[0].size();
        if (m==0)
            return 0;
        vector<vector<bool> > flag(n,vector<bool>(m,false));
        int ret=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) 
                if (!flag[i][j]&&grid[i][j]=='1') {
                    ret++;
                    floodFill(i,j,flag,grid);
                }
        return ret;
    }
};