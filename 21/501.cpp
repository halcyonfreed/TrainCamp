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
    int count=0; //cur元素出现次数
    int maxCount=0; //目前为止出现次数的max
    TreeNode* pre=nullptr; //初始化pre
    vector<int> result; //存众数
private:
// 因为直接更新全局变量result+ 搜索整棵树 
    void searchBST(TreeNode* cur){
        // 2 end
        if(cur==nullptr) return; //要写，代表立刻结束
        // 3 中序，递增
        searchBST(cur->left);

        // 中： 先更新count，再更新maxcount+result
        if(pre==nullptr) count=1;
        else if( pre->val==cur->val) count+=1;
        else count=1;

        if(count==maxCount) result.push_back(cur->val);
        else if(count>maxCount){
            maxCount=count;
            result.clear();//先清空之前存的众数，显然它们不是最终的众数
            result.push_back(cur->val);
        }

        pre=cur;

        // 右
        searchBST(cur->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return result;
    }
};