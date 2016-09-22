class Solution {
public:
    bool isSelfCrossing(vector<int>& len) {
        int n=len.size();
        for (int i=0;i<n;i++) {
            if (i>=3&&len[i]>=len[i-2]&&len[i-1]<=len[i-3]) {
                //cout<<i<<"　1";
                return true;
            }
                
            if (i>=4&&len[i]+len[i-4]>=len[i-2]&&len[i-1]==len[i-3]){
                //cout<<i<<"　2";
                return true;
            }
               
            if (i>=5&&len[i-4]+len[i]>=len[i-2]&&len[i-5]+len[i-1]>=len[i-3]&&len[i-3]>=len[i-1]&&len[i-2]>=len[i-4]){
                //cout<<i<<"　3";
                return true;
            }
               
        }
       
        return false;
    }
};