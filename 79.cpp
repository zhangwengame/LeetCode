class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        if (word.length()==0)
            return true;
        if (n==0||m==0) 
            return false;
        vector<vector<bool> > flag(n,vector<bool>(m,false));
        bool ret=false;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (dfs(i,j,flag,board,word,0)) 
                    return true;
            }
        return false;
    }
    bool dfs(int i,int j,vector<vector<bool> > &flag, vector<vector<char>>& board, string& word, int no) {
        if (word[no]!=board[i][j])
            return false;
        if (no==word.length()-1)
            return true;
        int n=board.size();
        int m=board[0].size();
        flag[i][j]=true;
        if (i>0&&!flag[i-1][j]&&dfs(i-1,j,flag,board,word,no+1)) {
            flag[i][j]=false;
            return true;
        }
        if (i<n-1&&!flag[i+1][j]&&dfs(i+1,j,flag,board,word,no+1)) {
            flag[i][j]=false;
            return true;
        }
        if (j>0&&!flag[i][j-1]&&dfs(i,j-1,flag,board,word,no+1)) {
            flag[i][j]=false;
            return true;
        }
        if (j<m-1&&!flag[i][j+1]&&dfs(i,j+1,flag,board,word,no+1)) {
            flag[i][j]=false;
            return true;
        }
        flag[i][j]=false;
        return false;
    }
    
};