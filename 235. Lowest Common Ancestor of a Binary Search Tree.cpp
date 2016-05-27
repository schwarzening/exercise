/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        int _min = p->val > q->val ? q->val : p->val;
        int _max = p->val <= q->val ? q->val : p->val;
        while(1) {
            if(_min <= cur->val && cur->val <= _max) {
                return cur;
            } else if (cur->val < _min) {
                cur = cur->right;   
            } else if (cur->val > _max) {
                cur = cur->left;
            }
        }
    }
};
