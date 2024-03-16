// 和112几乎一模一样！！
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
    // 设置成全局变量
    vector<int> path;
    vector<vector<int>> result;
private:
    // 1 返回所有path：要搜索整棵树；且返回值无额外操作，所以直接更新，无return
    // 1 param list: cur, count技巧不用sum用累减
    void traversal(TreeNode* cur, int count){
        // 2 end 遇到叶子
        if(!cur->left && !cur->right){
            if(count==0) {
                result.push_back(path);
                return; //如果不写return，不会立刻结束，还是要写的！！！return空，函数会立即结束，并且不会返回任何值。
            }
            else return;
        }

        // 3 单层logic
        if(cur->left){
            // 空node不递归
            path.push_back(cur->left->val);
            count-=cur->left->val;

            traversal(cur->left,count);
            
            path.pop_back();// pop没有值的
            count+=cur->left->val;
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            
            traversal(cur->right, count);   // 递归
            
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // 这两行不加会怎么样！！ 也可以没什么问题！！
        result.clear();
        path.clear();
        if(root==nullptr) return result;
        
        path.push_back(root->val);
        traversal(root,sum-root->val);
        return result;
    }
};