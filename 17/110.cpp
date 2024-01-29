class Solution {
private:
    int getHeight(TreeNode* node){
        if(node==nullptr) return 0;
        // 后序，求高度左右中
        // int leftHeight=getHeight(node->left);
        // int rightHeight=getHeight(node->right);
        // return 1+max(leftHeight,rightHeight);
        
        int leftHeight=getHeight(node->left);
        if (leftHeight==-1) return -1;
        int rightHeight=getHeight(node->right);
        if (rightHeight==-1) return -1;
        return abs(leftHeight-rightHeight)>1?-1:1+max(leftHeight,rightHeight);
    } //无分号
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1? false:true;
    }
};