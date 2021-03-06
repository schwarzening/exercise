/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example, 
 *  Given s = "Hello World", 
 *  return 5.
 */
 
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i --) {
            if(s[i] == ' ' && len == 0) continue;
            else if(s[i] == ' ' && len != 0) break;
            else len ++;
        }
        return len;
    }
};
