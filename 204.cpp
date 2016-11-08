class Solution {
public:
    int countPrimes(int n) {
        int ret=0;
        vector<bool> isPrime(n,true);
        for (int i=2;i<n;i++) {
            if (isPrime[i]) {
                ret++;
                int j=i+i;
                while (j<n) {
                    isPrime[j]=false;
                    j+=i;
                }
            }
        }
        return ret;
    }
};