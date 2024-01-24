#include<vector>
// 前序
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){} //没有分号！！！，加分号是空语句
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left, TreeNode* right): val(x),left(left),right(right){}
};

class Solution{
public:
    void traversal(TreeNode* cur,vector<int>& result){
        // 终止条件
        if(cur==NULL) return;
        // 单层逻辑，中左右
        result.push_back(cur->val);
        traversal(cur->left,result);
        traversal(cur->right,result);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};

// 这里的链表的输入输出比较难，还没搞！！