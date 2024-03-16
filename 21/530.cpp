// 简单的不难！！
class Solution {
private:
    int result=INT_MAX; //求最小值就初始化成最大值，直接更新这个，就不返回值了
    TreeNode* pre=nullptr; //初始化pre，双指针来记录cur的上一个
    void traversal(TreeNode* cur){
        // 2 结束
        if(cur==nullptr) return;

        // 3 单层 二叉搜索 条件反射 中序遍历
        traversal(cur->left);

        // 这里出错 因为pre可能是null 
        if(pre!=nullptr && cur->val-pre->val < result) result=cur->val-pre->val;
        pre=cur;

        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};