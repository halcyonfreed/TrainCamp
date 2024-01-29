class Solution {
private:
    int getNodeSum(TreeNode* node){
        if(node==nullptr) return 0;

        // 左右中
        int leftCnt=getNodeSum(node->left);
        int rightCnt=getNodeSum(node->right);
        return 1+leftCnt+rightCnt; //和！ 算上自己所以+1
        
    }
public:
    int countNodes(TreeNode* root) {
        // 普通法——递归
        return getNodeSum(root);
    }
};

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
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que; // 定义单向队列，存遍历节点；不用双向deque
        if(root!=nullptr) que.push(root);  //初始化队列赋值
        int result=0; //选做，根据需求自定义结果

        while(!que.empty()){
            //while条件，队非空
            int size=que.size(); //这一层的节点数
            for(int i=0;i<size;i++){
                //中
                TreeNode* node=que.front(); 
                que.pop();	
                result++;
                //左右，后序
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};



class Solution {
public:
    int countNodes(TreeNode* root) {
        // 遍历左右
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left) {  // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while (right) { // 求右子树深度
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            // 满二叉
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;// 后序，左右中
    }
};