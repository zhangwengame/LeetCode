class Solution {
public:
    int calculate(string s) {
        stack<int> results,ops;
        int num=0;
        int sign=1;
        int result=0;
        for (int i=0;i<s.length();i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                num=num*10+s[i]-'0';
            } else if (s[i]=='+') {
                result+=sign*num;
                sign=1;
                num=0;
            } else if (s[i]=='-') {
                result+=sign*num;
                sign=-1;
                num=0;
            } else if (s[i]=='(') {
                results.push(result);
                ops.push(sign);
                sign=1;
                num=0;
                result=0;
            } else if (s[i]==')') {
                result+=sign*num;
                sign=1;
                num=0;
                result=results.top()+ops.top()*result;
                results.pop();
                ops.pop();
            }
        }
        return result+sign*num;
    }
};