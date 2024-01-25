// 前序  中左右
// 迭代法，用的是栈：所以是中右左压入，中左右弹出
#include<stack>
#include<vector>
using namesapce std;

class Solution{
public:
    vector<int> preorderTraversal(TreedNode* root){
        stack<TreeNode*> st; //遍历节点
        vector<int> result;

        if(root==NULL) return result; //特殊情况，如果本来就是空的树，就返回空

        st.push(root); //初始化压入
        while(!st.empty()){
            // 弹出顶,
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val); //遇到中间，先弹中间，再压右和左
            if(node->right) st.push(node->right); //if会忘！！！
            if(node->left) st.push(node->left);
        }
        return result;
    }
};