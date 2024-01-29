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
    int minDepth(TreeNode* root) {
        // 2 end
        if(root==nullptr) return 0; //本来就空，停
        // 后序 左右中
        // 左
        int leftDepth=minDepth(root->left);
        // 右
        int rightDepth=minDepth(root->right);
        // 中
        int result;
        // 不对
        // if(root->left && root->right!=nullptr) return 1+rightDepth;
        // else if(root->right && root->left!=nullptr) return 1+leftDepth;
        // else return 1+min(rightDepth,leftDepth);
        
        if(root->left==nullptr && root->right!=nullptr) result=1+rightDepth; 
        else if(root->right==nullptr && root->left!=nullptr) result= 1+leftDepth;
        else result= 1+min(rightDepth,leftDepth);
        
        cout<<result<<endl;
        return result;
    }
};