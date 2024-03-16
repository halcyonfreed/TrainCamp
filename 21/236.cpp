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
        // 2结束 如果当前就是空 当前就是p或者q，那就返回自身到上一层去
        if(root==nullptr || root==q || root==p) return root;

        // 3 单层逻辑
        // 后序，从下往上，左右中 搜整棵树，leftright返回值一起判断，再返回到root
        TreeNode* left= lowestCommonAncestor(root->left, p,q); //套娃
        TreeNode* right= lowestCommonAncestor(root->right,p,q); //套娃

        if(left==nullptr && right!=nullptr) return right;
        else if(left!=nullptr && right== nullptr) return left;
        else if(left!=nullptr && right!=nullptr) return root;
        else return nullptr; //左右返的都是空

        
    }
};