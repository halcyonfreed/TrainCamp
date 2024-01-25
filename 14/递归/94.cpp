#include<vector>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

class Solution{
public:
    void traversal(TreeNode* cur, vector<int>& result){
        // 单层遍历干两件事： 遍历； 加入结果
        if(cur==NULL) return;
        // 中序，左中右
        traversal(cur->left,result);
        result.push_back(cur->val);
        traversal(cur->right,result);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};