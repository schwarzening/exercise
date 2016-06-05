/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string str_com;
        int flag = 0;
        for(int i = 0; i < strs[0].size(); i ++) {
            str_com.push_back(strs[0][i]);
            flag = 0;
            for (int j = 0;j < strs.size(); j ++) {
                if(strs[j][i] != str_com.back()) {
                    str_com.pop_back();
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        return str_com;
    }
};
