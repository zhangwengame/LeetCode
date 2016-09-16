class Solution {
public:
    void reverseWords(string &s) {
        int len=s.length();
        int begin=0;
        while (begin<len&&isspace(s[begin]))
            begin++;
        if (begin>=len) {
            s.resize(0);
            return;
        }
        int end=len-1;
        while (end>=0&&isspace(s[end]))
            end--;
        for (int i=begin;i<=end;i++)
            s[i-begin]=s[i];
        s.resize(end-begin+1);
        int i=0;
        int j=0;
        len=s.length();
        while (j<len){
            if (!isspace(s[j])) {
                s[i]=s[j];
                i++;
                j++;
                continue;
            }
            while (j<len&&isspace(s[j])) 
                j++;
            s[i]=' ';
            i++;
        }
        s.resize(i);
        len=s.length();
        for (int i=0;i<len/2;i++){
            char tmp=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=tmp;
        }
        i=0;
        while (i<len) {
            j=s.find(' ',i);
            if (j==string::npos)
                j=len-1;
            else
                j--;
            for (int pos=0;pos<(j-i+1)/2;pos++){
                char tmp=s[i+pos];
                s[i+pos]=s[j-pos];
                s[j-pos]=tmp;;
            }
            i=j+2;
        }
    }
};