/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 1 就用题给的
        // 2 终止条件
        if (root==nullptr) return 0;//自己是空的，左孩子之和一定是0
        if (root->left==nullptr && root->right==nullptr) return 0; //下一层是空，所以自己是叶子，所以左孩子之和是0

        int result;

        // 3 叶子 左右中，从下往上累加
        int leftSum=sumOfLeftLeaves(root->left); //一般情况，正常套娃就行，下面这种需要算leftsum！！
        if(root->left && !root->left->left&& !root->left->right){
            leftSum=root->left->val;//左孩子是叶子，就是左孩子的下一层都是空的，则左孩子自己是叶子！
        } 

        int rightSum=sumOfLeftLeaves(root->right);
        result=leftSum+rightSum;
        return result;
    }
};