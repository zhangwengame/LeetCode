class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i=0;i<s.length();i++){
            switch (s[i]) {
                case '{':
                sta.push('{');
                break;
                case '[':
                sta.push('[');
                break;
                case '(':
                sta.push('(');
                break;
                case '}':
                if (!sta.empty()&&sta.top()=='{')
                    sta.pop();
                else
                    return false;
                break;
                case ']':
                if (!sta.empty()&&sta.top()=='[')
                    sta.pop();
                else
                    return false;
                break;
                case ')':
                if (!sta.empty()&&sta.top()=='(')
                    sta.pop();
                else
                    return false;
                break;
            }
        }
        if (!sta.empty())
            return false;
        return true;
    }
};