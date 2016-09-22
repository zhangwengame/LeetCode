class Solution {
public:
    void calculateQueen(int i,int n, vector<bool> &vertical,vector<bool> &lrdiagonal,vector<bool> &rldiagonal,
        int  &ret) {
        if (i==n) {
            ret++;
            return;
        }
        for (int j=0;j<n;j++) {
            if (!vertical[j]&&!lrdiagonal[i-j+n-1]&&!rldiagonal[i+j]) {
                vertical[j]=true;
                lrdiagonal[i-j+n-1]=true;
                rldiagonal[i+j]=true;
                calculateQueen(i+1,n,vertical,lrdiagonal,rldiagonal,ret);
                vertical[j]=false;
                lrdiagonal[i-j+n-1]=false;
                rldiagonal[i+j]=false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool> vertical(n,false);
        vector<bool> lrdiagonal(2*n-1,false);
        vector<bool> rldiagonal(2*n-1,false);
        int ret=0;
        calculateQueen(0,n, vertical,lrdiagonal,rldiagonal,ret);
        return ret;
    }
};