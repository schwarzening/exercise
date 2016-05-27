/* Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 *  Given sorted array nums = [1,1,1,2,2,3],
 *  Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int index = 0;
        int count = 0;
        int tmp = nums[0];
        nums[index++] = tmp;
        count = 1;
        for(int i = 1;i < nums.size(); i ++) {
            if((nums[i] == tmp) && (count < 2)) {
                nums[index++] = tmp;
                count ++;
            } else if(nums[i] != tmp) {
                nums[index++] = nums[i];
                count = 1;
                tmp = nums[i];
            }
        }
        return index;
    }
};
