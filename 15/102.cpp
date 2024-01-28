class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> que; //存遍历的结果

        if(root!=NULL) que.push(root);//特殊情况

        vector<vector<int>> result; //存结果

        while(!que.empty()){
            int size=que.size();
            vector<int> vec;  //记录的是这一层的元素

            for(int i=0;i<size;i++){
                // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
                TreeNode* node=que.front(); 
                que.pop();
                vec.push_back(node->val);

                if(node->left) que.push(node->left); //que队列先进先出，从左到右
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};