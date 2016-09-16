class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        int ret=numeric_limits<int>::min();
        int n=matrix.size();
        int m=matrix[0].size();
        if (n>=m) {
            for (int l=0;l<m;l++) {
                vector<int> totSum(n,0);
                for (int r=l;r<m;r++) {
                    int columnSum=0;
                    set<int> rowSet;
                    rowSet.insert(0);
                    for (int i=0;i<n;i++) {
                        columnSum+=matrix[i][r];
                        totSum[i]+=columnSum;
                        auto it=rowSet.lower_bound(totSum[i]-k);
                        if (it!=rowSet.end()&&totSum[i]-*it>ret) ret=totSum[i]-*it;
                        rowSet.insert(totSum[i]);
                    }
                }
            }
        } else {
             for (int u=0;u<n;u++) {
                vector<int> totSum(m,0);
                for (int d=u;d<n;d++) {
                    int rowSum=0;
                    set<int> columnSet;
                    columnSet.insert(0);
                    for (int j=0;j<m;j++) {
                        rowSum+=matrix[d][j];
                        totSum[j]+=rowSum;
                        auto it=columnSet.lower_bound(totSum[j]-k);
                        if (it!=columnSet.end()&&totSum[j]-*it>ret) ret=totSum[j]-*it;
                        columnSet.insert(totSum[j]);
                    }
                }
            }
        }

        return ret;
    }
};