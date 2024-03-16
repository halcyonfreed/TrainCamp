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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 2 end
        if (root==nullptr) return root;
        // 直接处理中，当不在范围里修剪 不是return null；应剪，因为BST特性
        // <L,右子再找
        if(root->val<low) return trimBST(root->right,low,high);
        // >R 左子再找
        if(root->val>high) return trimBST(root->left,low,high);

        // 3 单层 中序
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};