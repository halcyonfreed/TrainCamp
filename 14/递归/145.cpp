// 后序
#include<vector>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left,TreeNode* right): val(x),left(left),right(right){}
};

class Solution{
public:
    void traversal(TreeNode* cur,vector<int>& result){
        if(cur==NULL) return;
        // 左右中
        traversal(cur->left,result);//左
        traversal(cur->right,result); //右
        result.push_back(cur->val); //中
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};