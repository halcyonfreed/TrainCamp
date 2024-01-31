// 解法一
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 层序遍历，用队列
        queue<TreeNode*> que; //指向 TreeNode 对象的指针，不要漏了*
        if(root!=nullptr) que.push(root); //初始化！！
        int result;

        while(!que.empty()){
            int size=que.size(); //这一层的大小
            // 中左右前序遍历这一层的，同时遍历压入左右孩子；同时更新结果
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(i==0) result=node->val;//这层第一个
                
                if(node->left)que.push(node->left); //压下一层的
                if(node->right)que.push(node->right);
            }
        }
        return result;
    }
};

// 递归法，求深度（root到node距离）
class Solution {
public:
    int maxDepth=INT_MIN;
    int result;
    void traversal(TreeNode* root,int depth){
        // 从上往下，前序 中左右
        // 2 end 条件+动作
        if(root->left==nullptr && root->right==nullptr){
            if(depth>maxDepth){
                maxDepth=depth;
                result=root->val;
            }
        }

        if(root->left){
            depth++;
            traversal(root->left,depth);
            depth--; //回溯
            // 可以简化成 traveresal(root->left,depth+1);
        }
        if(root->right){
            traversal(root->right,depth+1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return result;
    }
};