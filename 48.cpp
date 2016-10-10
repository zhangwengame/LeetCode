class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if (n==0) 
            return;
        int m=matrix[0].size();
        if (m==0)
            return;
        double cx=0.5*(m-1);
        double cy=0.5*(n-1);
        int tmp[4];
        for (int i=0;i<cx;i++)
            for (int j=i;j<m-i-1;j++) {
                double ny=cy-i;
                double nx=j-cx;
                tmp[0]=matrix[cy-ny][nx+cx];
                for (int k=0;k<3;k++) {
                    double t=nx;
                    nx=ny;
                    ny=-t;
                    tmp[1+k]=matrix[cy-ny][nx+cx];
                }
                ny=cy-i;
                nx=j-cx;
                for (int k=0;k<4;k++) {
                    matrix[cy-ny][nx+cx]=tmp[(k+3)%4];
                    double t=nx;
                    nx=ny;
                    ny=-t;
                }
            }
    }
};