class Solution {
public:
    int reverse(int x) {
        int ret=0;
        while (x) {
            if ((x>0)&&((numeric_limits<int>::max()/10>ret)||((numeric_limits<int>::max()/10==ret)&&(x%10<=7)))
            ||(x<0)&&((numeric_limits<int>::min()/10<ret)||((numeric_limits<int>::min()/10==ret)&&(x%10>=-8)))) {
                ret=ret*10+x%10;
                x/=10;
            } else {
                ret=0;
                break;
            }
     
        }
        return ret;
    }
};