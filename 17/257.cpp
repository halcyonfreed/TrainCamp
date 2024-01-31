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
private:
    void traversal(TreeNode* node, vector<int>& path, vector<string>& result){
        path.push_back(node->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
        // 前序
        // 2 终止条件，下一层孩子是叶子
        string spath;
        if(node->left==nullptr && node->right==nullptr){
            // for(int i=0;i<path.size()-1;++i){
            //     result.push_back(to_string(path[i]));
            //     result.push_back("->");
            // }
            // result.push_back(to_string(path[path.size()-1]));  //["1","->","2","1"]
            // string spath;
            for(int i=0;i<path.size()-1;++i){
                spath+=to_string(path[i]); //不可以写=  是+=
                spath+="->";
            }
            spath+=to_string(path[path.size()-1]);
            result.push_back(spath);
        }

        // 3 前序 中左右; 套娃
        // path.push_back(node->val);  //中放这里最后一个进不去，最后一个叶子就压不进去了，为什么，要放在终止条件之前
        // 先判非空,回溯要在{}内！！
        if(node->left){
            traversal(node->left,path,result);
            path.pop_back();
        }
        if(node->right){
            traversal(node->right,path,result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root==nullptr) return result;//忘记特殊情况
        traversal(root,path,result);
        return result;
    }
};