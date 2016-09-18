class Solution {
public:
    string convertHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int h=num/100;
        int x=num%100;
        int y=num%10;
        string ret;
        if (h>0)
            ret+=v1[h]+" Hundred"+(x>0?" ":"");
        if (x<20)
            ret+=v1[x];
        else 
            ret+=v2[x/10]+(y>0?" ":"")+v1[y];
        return ret;
    }
    string numberToWords(int num) {
        if (num==0)
            return "Zero";
        vector<string> v1={"","Thousand","Million","Billion"};
        string ret("");
        int flag=0;
        for (int i=0;i<4;i++){
            int tmp=num%1000;
            ret=(tmp>0?convertHundred(tmp)+(i==0?"":" ")+v1[i]+((i==0||flag==0)?"":" "):"")+ret;
            if (tmp!=0)
                flag=1;
            num/=1000;
        }
        return ret;
    }
};