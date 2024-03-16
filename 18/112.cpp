// 沉下心来，告诉自己的努力不会白费，种因才有果，平心静气
class Solution{
private:
// 未对中间node做操作，所以前中后序都行，还是前序认为
// 1 return type + param list
    bool traversal(TreeNode* cur, int count){
        // 2 end condition(一般是遇到叶子了)
        if(!cur->left && !cur->right){
            if(count==0) return true;
            else return false;
        }

        // 3 单层logic
        // 特殊！！！空的node不做递归！
        if(cur->left){
            count-=cur->left->val;
            // 这行难写，如果上一层套娃返回true，那么这一层返回下一层套娃是true
            // 最终要把这个true 返回到套娃第一层，即root去
            if(traversal(cur->left,count)) return true;
            count+=cur->left->val; //如果没有return，那么自然没跳出去，就回溯上一层
        }

        // 如果上一个if没有return，那么已经回溯到原来的地方，就开始往右孩子找
        if(cur->right){
            count-=cur->right->val;
            if(traversal(cur->right,count)) return true;
            count+=cur->right->val;
        }

        return false; //上面都没找到，就false
    }

public:
    bool hasPathSum(TreeNode* root, int sum){
        if(root==nullptr) return false; //特殊情况单独处理
        return traversal(root,sum-root->val);
    }
};