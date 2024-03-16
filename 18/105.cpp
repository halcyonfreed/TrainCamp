// 2.28 默写耗时 15分钟 一遍AC 说明做的不错！！昨天消化了！！

class Solution{
private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd){
        // 2 结束条件
        // 先用前序
        if(preorderEnd==preorderBegin) return nullptr;

        int rootValue=preorder[preorderBegin];
        TreeNode* root= new TreeNode(rootValue);

        if(preorderEnd-preorderBegin==1) return root;

        // 3单层 切
        // 先用前序第一个切中序
        int delimiterIndex;
        for(delimiterIndex=0;delimiterIndex<inorderEnd;delimiterIndex++){
            if(inorder[delimiterIndex]==rootValue) break;
        }

        int leftInorderBegin=inorderBegin;
        int leftInorderEnd=delimiterIndex;
        int rightInorderBegin=delimiterIndex+1;
        int rightInorderEnd=inorderEnd;

        int leftPreorderBegin=preorderBegin+1;
        int leftPreorderEnd=leftPreorderBegin+(delimiterIndex-inorderBegin);
        int rightPreorderBegin=leftPreorderEnd;
        int rightPreorderEnd=preorderEnd;
        
        root->left=traversal(inorder,leftInorderBegin,leftInorderEnd,preorder,leftPreorderBegin,leftPreorderEnd);
        root->right=traversal(inorder,rightInorderBegin,rightInorderEnd,preorder,rightPreorderBegin,rightPreorderEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(inorder,0,inorder.size(),preorder,0,preorder.size());
    }
};