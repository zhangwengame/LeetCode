class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        vector<vector<int> > f(size1+1,vector<int>(size2+1,0));
        for (int i=0;i<=size1;i++)
            f[i][0]=i;
         for (int j=0;j<=size2;j++)
            f[0][j]=j;   
        for (int i=1;i<=size1;i++)
            for (int j=1;j<=size2;j++){
                if (word1[i-1]==word2[j-1])
                    f[i][j]=f[i-1][j-1];
                else {
                    f[i][j]=f[i][j-1]+1;
                    if (f[i-1][j]+1<f[i][j])
                        f[i][j]=f[i-1][j]+1;
                    if (f[i-1][j-1]+1<f[i][j])
                        f[i][j]=f[i-1][j-1]+1;
                }
            }
            
        return f[size1][size2];
    }
};