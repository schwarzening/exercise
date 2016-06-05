/*
 * Write a function that takes a string as input and returns the string reversed.
 */
 
class Solution {
public:
    string reverseString(string s) {
        string t = s;
        int len = s.size();
        for(int i = 0; i < len; i ++) {
            t[len - 1 - i] = s[i];
        }
        return t;
    }
};
