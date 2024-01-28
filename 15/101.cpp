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
class Solution{
public:
    bool compare(TreeNode* left, TreeNode* right){
        // 终止条件，左右子树存在叶子节点了
        if(left==nullptr && right !=nullptr) return false; //左空叶子，右不空
        else if(left!=nullptr && right ==nullptr) return false;
        else if(left==nullptr && right ==nullptr) return true;
        else if(left->val!=right->val) return false;  // 左右都不空

        // 单层逻辑，左右都不空且相同，就判下一层，递归了
        // 后序 左子树左右中，右子树右左中
        
        bool inside= compare(left->right,right->left);//内测，内外侧部分先后顺序都可AC，比左子树的右=右子树的左？
        bool outside= compare(left->left,right->right);//外侧，比左子树的左=右子树的右？
        bool isSame=outside&& inside; // 左子树：中、 右子树：中（逻辑处理）返到上一层的爸爸父节点
        return isSame;
    }

    bool isSymmetric(TreeNode* root){
        if(root==nullptr) return true;
        return compare(root->left,root->right);
    }
};