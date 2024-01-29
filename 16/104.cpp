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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        // 递归是用套娃代替while，for循环
        int leftDepth=maxDepth(root->left); //左
        int rightDepth=maxDepth(root->right);// 右
        int midDepth=1+max(leftDepth,rightDepth); //中，上一层的爸爸
        return midDepth;
    }
};