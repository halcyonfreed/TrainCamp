#include<algorithm>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 2 end condition
        if(root==nullptr) return root;
        // 单层logic 前序、后序
        swap(root->left,root->right); //左右孩子换
        invertTree(root->left);    //左子树全换 开始套娃
        invertTree(root->right);
        return root;
    }
};