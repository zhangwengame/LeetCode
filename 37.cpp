class Solution {
public:
    int sub2linear(int i,int j){
        return (i/3)*3+(j/3);
    }
    void dfs(int no,vector<pair<int,int>>& searchList,vector<vector<bool>>& column,
             vector<vector<bool>>& line, vector<vector<bool>>& grid,vector<vector<char>>& board, bool& solved) {
                 if (no==searchList.size()) {
                     solved=true;
                     return;
                 }
                 int y=searchList[no].first;
                 int x=searchList[no].second;
                 //printf("%d %d %d\n",no,y,x);
                 for (int i=0;i<9;i++)
                    if (!line[y][i]&&!column[x][i]&&!grid[sub2linear(y,x)][i]) {
                        //printf("%d %d %d\n",y,x,i);
                        line[y][i]=true;
                        column[x][i]=true;
                        grid[sub2linear(y,x)][i]=true;
                        board[y][x]='1'+i;
                        dfs(no+1,searchList,column,line,grid,board,solved);
                        if (solved) 
                            return;
                        line[y][i]=false;
                        column[x][i]=false;
                        grid[sub2linear(y,x)][i]=false;
                    }
             }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> column(9,vector<bool>(9,false));
        vector<vector<bool>> line(9,vector<bool>(9,false));
        vector<vector<bool>> grid(9,vector<bool>(9,false));
        vector<pair<int,int>> searchList;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (board[i][j]!='.') {
                    line[i][board[i][j]-'1']=true;
                    column[j][board[i][j]-'1']=true;
                    grid[sub2linear(i,j)][board[i][j]-'1']=true;
                } else
                    searchList.push_back(make_pair(i,j));
        bool solved=false;
        dfs(0,searchList,column,line,grid,board,solved);
    }
};