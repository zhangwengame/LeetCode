class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1)
            return 0;
        int ret=0;
        int minP=prices[0];
        for (int i=1;i<prices.size();i++) {
            if (prices[i]-minP>ret)
                ret=prices[i]-minP;
            minP=min(prices[i],minP);
        }
        return ret;
    }
};