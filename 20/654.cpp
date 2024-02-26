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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node= new TreeNode(0);//用来遍历

        // 结束条件
        if(nums.size()==1) {
            node->val=nums[0]; //改val值
            return node;
        } // 遍历玩了，叶子

        // 开始递归
        // 先找到最大，然后更新中间值
        int maxValue=0;
        int index=0; //要记录下标，不然没法分割区间
        for (int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue=nums[i];
                index=i;
            }
        }
        node->val=maxValue;

        // 左
        // 同时满足终止条件
        if(index>0){
            // node->left=constructMaximumBinaryTree(nums[:index]); //这是python的写法！！！
            vector<int> newvec(nums.begin(),nums.begin()+index); // 默认左闭右开
            node->left=constructMaximumBinaryTree(newvec);
        }

        // 右
        if(nums.size()-index>1){
            // node->right=constructMaximumBinaryTree(nums[index+1:]);
            vector<int> newvec(nums.begin()+index+1,nums.end());
            node->right=constructMaximumBinaryTree(newvec);
        }
        return node;
    }
};

// 另外构造自定义的递归函数
class Solution{
private:
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if (left>=right)  return nullptr; // end条件
        
        // 找最大，更新
        int maxValueIndex=left;
        for(int i=left+1; i<right;++i){
            if(nums[i]>nums[maxValueIndex]) maxValueIndex=i;
        }
        TreeNode* root=new TreeNode(nums[maxValueIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);

        // 左闭右开：[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};