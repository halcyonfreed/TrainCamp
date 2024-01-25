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
    // void traversal(TreeNode* cur,vector<int>& result){
    //     if(cur==NULL) return;
    //     // 左右中
    //     traversal(cur->left,result);//左
    //     traversal(cur->right,result); //右
    //     result.push_back(cur->val); //中
    // }

    // vector<int> postorderTraversal(TreeNode* root){
    //     vector<int> result;
    //     traversal(root,result);
    //     return result;
    // }

    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st; //遍历 元素是node=val+指针
        vector<int> result; //存结果

        if(root==NULL) return result; //特殊情况
        st.push(root);

        while(!st.empty()){
            TreeNode* cur=st.top();
            st.pop();//先取再删！！

            result.push_back(cur->val); //压入结果
            
            //这里也要改顺序，为什么，因为最后reverse了，所以这里左右也要改
            
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};