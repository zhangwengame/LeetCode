class Solution {
public:
    double myPow(double x, int n) {
        double ret=1.0;
        bool positive=true;
        size_t N;
        N=n;
        if (n<0) {
            positive=false;
            N=-n;
        }
        while (N) {
            if (N&1==1){
                ret*=x;
            }
            x*=x;
            N>>=1;
        }
        if (!positive)
            ret=1/ret;
        return ret;
    }
};