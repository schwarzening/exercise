/* Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example:
 *  Given input array nums = [3,2,2,3], val = 3
 *  Your function should return length = 2, with the first two elements of nums being 2.
 */
 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index ++;
            }
        }
        return index;
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        auto it1 = nums.begin();
        int num = 0;
        for(auto it = nums.begin(); it != nums.end(); it ++) {
            if (*it == val) {
                it1 = it;
                break;
            }
        }
        for(auto it = it1; it != nums.end(); it ++) {
            if (*it == val) {
                num ++;
            }
        }
        nums.erase(it1,it1+num);
        return nums.size();
    }
};
