class Solution {
public:
    void calculateQueen(int i,int n, vector<bool> &vertical,vector<bool> &lrdiagonal,vector<bool> &rldiagonal,
        vector<int> &pos, vector<vector<string> >  &ret) {
        if (i==n) {
            vector<string> ans;
            for (int line=0;line<n;line++) {
                string tmp;
                tmp.append(n,'.');
                tmp[pos[line]]='Q';
                ans.push_back(tmp);
            }
            ret.push_back(ans);
            return;
        }
        for (int j=0;j<n;j++) {
            if (!vertical[j]&&!lrdiagonal[i-j+n-1]&&!rldiagonal[i+j]) {
                pos[i]=j;
                vertical[j]=true;
                lrdiagonal[i-j+n-1]=true;
                rldiagonal[i+j]=true;
                calculateQueen(i+1,n,vertical,lrdiagonal,rldiagonal,pos,ret);
                vertical[j]=false;
                lrdiagonal[i-j+n-1]=false;
                rldiagonal[i+j]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> vertical(n,false);
        //vector<bool> horizontal(n,false);
        vector<bool> lrdiagonal(2*n-1,false);
        vector<bool> rldiagonal(2*n-1,false);
        vector<vector<string> > ret;
        vector<int> pos(n);
        calculateQueen(0,n, vertical,lrdiagonal,rldiagonal,pos,ret);
        return ret;
    }
};