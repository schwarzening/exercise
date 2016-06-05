/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
 
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int cnt = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
                cnt ++;
            }
            if(s[i] == ')' && stk.empty()) return false;
            if(s[i] == ']' && stk.empty()) return false;
            if(s[i] == '}' && stk.empty()) return false;
            if(s[i] == ')') {
                if(stk.top() == '(') stk.pop();
                cnt --;
            }
            if(s[i] == ']') {
                if(stk.top() == '[') stk.pop();
                cnt --;
            }
            if(s[i] == '}') {
                if(stk.top() == '{') stk.pop();
                cnt --;
            }
        }
        return stk.empty() && cnt == 0;
    }
};
