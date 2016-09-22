class Solution {
public:
    vector<int> maxKArray(vector<int> &a, int k) {
        vector<int> ret(k);
        int len=a.size();
        int top=-1;
        for (int i=0; i<a.size(); i++) {
            while (top>=0&&len-i+top+1>k&&a[i]>ret[top])
                top--;
            if (top<k-1) {
                top++;
                ret[top]=a[i];
            }
        }
        return ret;
    }
    bool great(vector<int> &num1, int i,vector<int> &num2, int j) {
        while (i<num1.size()&&j<num2.size()&&num1[i]==num2[j]) {
            i++;
            j++;
        }
        return j==num2.size()||(i<num1.size()&&num1[i]>num2[j]);
    }
    vector<int> merge(vector<int> &num1, vector<int> &num2, int k) {
        int i=0;
        int j=0;
        vector<int> ret(k);
        for (int no=0;no<k;no++) {
            if (great(num1,i,num2,j))
                ret[no]=num1[i++];
            else
                ret[no]=num2[j++];
        }
        return ret;
    }
    vector<int> maxNumber(vector<int>& num1, vector<int>& num2, int k) {
        int n=num1.size();
        int m=num2.size();
        vector<int> ret(k);
        for (int i=max(k-m,0);i<=k&&i<=n;i++){
            vector<int> a1=maxKArray(num1,i);
            //cout<<1<<endl;
            vector<int> a2=maxKArray(num2,k-i);
            //cout<<2<<endl;
            vector<int> tmp=merge(a1,a2,k);
           // cout<<3<<endl;
            if (great(tmp,0,ret,0))
                ret=tmp;
        }
        return ret;
    }
};