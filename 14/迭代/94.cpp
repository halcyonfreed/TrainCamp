// 中序最难！！  左中右，不能先压，要先找到左才压
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; //存遍历的node
        vector<int> result; //存result
        TreeNode* cur=root; //用来遍历


        // 次数不定用while
        while(cur!=NULL || !st.empty()){
            // 非叶子节点，或者非空！
            // 最后写条件！
            if(cur!=NULL){//一路只往左，直到访问到最底层左叶子
                st.push(cur);
                cur=cur->left;
            }else{
                cur=st.top();
                st.pop();
                result.push_back(cur->val);//中

                cur=cur->right;//右
            }
        }
        return result;
    }
};