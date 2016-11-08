class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > block(9,vector<bool>(9,false));
        vector<vector<bool> > vertical(9,vector<bool>(9,false));
        vector<vector<bool> > horizontal(9,vector<bool>(9,false));
        for (int i=0;i<9;i++) 
            for (int j=0;j<9;j++) {
                if (board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    int r=i/3;
                    int c=j/3;
                    if (vertical[j][num])
                        return false;
                    if (horizontal[i][num])
                        return false;
                    if (block[r*3+c][num])
                        return false;
                    vertical[j][num]=true;
                    horizontal[i][num]=true;
                    block[r*3+c][num]=true;
                }
            }
        return true;
    }
};