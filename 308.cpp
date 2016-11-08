class NumMatrix {
public:
    int lowbit(int x){
        return x&(-x);
    }
    void add(int x,int i,int j){
        i++;
        j++;
        for (int ni=i;ni<=n;ni+=lowbit(ni))
            for (int nj=j;nj<=m;nj+=lowbit(nj)) {
                c[ni][nj]+=x;
            }
    }
    int sum(int i,int j){
        i++;
        j++;
        int ret=0;
        for (int ni=i;ni>0;ni-=lowbit(ni))
            for (int nj=j;nj>0;nj-=lowbit(nj)) {
                ret+=c[ni][nj];
            }
        return ret;
    }
    NumMatrix(vector<vector<int> > &matrix) {
        a=matrix;
        n=matrix.size();
        if (n==0)
            return;
        m=matrix[0].size();
        if (m==0)
            return;
        c=vector<vector<int> >(n+1,vector<int>(m+1,0));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                add(a[i][j],i,j);
            }
    }

    void update(int row, int col, int val) {
        if (n==0||m==0)
            return;
        int diff=val-a[row][col];
        a[row][col]=val;
        add(diff,row,col);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (n==0||m==0)
            return 0;
        int ret=sum(row2,col2);
        ret-=sum(row1-1,col2);
        ret-=sum(row2,col1-1);
        ret+=sum(row1-1,col1-1);
        return ret;
    }
private:
    vector<vector<int> > c;
    vector<vector<int> > a;
    int n;
    int m;
};