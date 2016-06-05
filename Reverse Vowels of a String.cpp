/*
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * Example 1:
 *  Given s = "hello", return "holle".
 * Example 2:
 *  Given s = "leetcode", return "leotcede".
 */
 
class Solution {
public:
    bool is_vowels (char ch) {
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O'|| ch == 'u' || ch == 'U');
    }
    string reverseVowels(string s) {
        string t;
        int len = s.size();
        for(int i = 0; i < len; i ++) {
            if(is_vowels(s[i])) t.push_back(s[i]);
        }
        len = t.size();
        for(int i = 0, index = 0; index < len; i ++) {
            if(is_vowels(s[i])) {
                s[i] = t[len - 1 - index];
                index ++;
            }
        }
        return s;
    }
};
