/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 */
class Solution {
public:
    bool isal(char ch) {
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
	}
    bool isPalindrome(string s) {
        int len = s.length();
        //cout << "len: " << len << endl;
        if(len == 0) return true;
        for(int i = 0;i < s.length();i ++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] - 'A' + 'a';
			}
		}
        int num = 0;
        for(int i = 0;i < len;i ++) {
        	if(isal(s[i])) num ++;
		}
		//cout << "num: " << num << endl;
        for(int cnt = 0, i = 0, j = len - 1; cnt < num / 2;) {
			//cout << s[i] << " " << s[j] << endl;
			if(!isal(s[i])) {
        		i++;
        		continue;
			}
			if(!isal(s[j])) {
        		j--;
        		continue;
			}
			if(s[i] != s[j]) return false;
			i ++;
			j --;
			cnt ++;
		}
		return true;
    }
};
