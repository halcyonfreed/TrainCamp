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

//  不释放内存版本！
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) { 
        // 2 end 直接处理root
        // 2.1 找不到root
        if(root==nullptr) return nullptr; //找到最后也没找到就啥也不做
        //  找到了
        if(root->val==key){
            // 2.2 叶子 把自己删了，把空返回上一层的爸爸
            if (root->left==nullptr && root->right==nullptr) return nullptr;
            // 2.3 左不空，右空；把左返回给爸爸的左
            else if(root->left!=nullptr && root->right==nullptr) return root->left;

            // 2.4 左空 右不空
            else if(root->left==nullptr && root->right!=nullptr) return root->right;
            // 2.5 左右都不空，左右孩子都可以作为爸爸的新孩子；if左，就把右塞到左的最右（最大）；if右，就把左塞到右的最左（最小）
            else{
                // 请注意顺序问题！！！：先塞，即先更新孩子，再让old爸爸借助新孩子；
                // 用右孩子 作为old爸爸的新孩子
                // 这个不会：先找右的最左，右的最小的; 用while 自定义cur
                TreeNode* cur=root->right;
                while(cur->left!=nullptr){
                    cur=cur->left; //一路找到右孩子子树里最左的 因为最小，把old左孩子塞到下面
                }
                cur->left=root->left;
                root=root->right; //塞完以后，再更新爸爸接住删完以后的新孩子！！！ 没有return

            }
        }

        // 3 单层 "中"已经在2处理了， 所以就左右无所谓
        // 用bst性质，往哪里搜索
        if(root->val>key) root->left=deleteNode(root->left,key); // 把左边的全部套娃更新
        if(root->val<key) root->right=deleteNode(root->right,key); //大了，把右边的全部套娃更新
        return root;
    }
};

// 删除内存版本：定义一个临时的存root 然后删root
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 2 end 5种就是处理"中"
        // 2.1 没找到
        if(root==nullptr) return root;
        // 找到了
        if(root->val==key){
            // 2.2 找到叶子
            if(root->left==nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // 2.3 左不空，右空；把左返回给爸爸的左
            else if(root->left!=nullptr && root->right==nullptr){
                TreeNode* cur=root->left;
                delete root;
                return cur;                
            }
            // 2.4 左空 右不空
            else if(root->left==nullptr && root->right!=nullptr){
                TreeNode* cur=root->right;
                delete root;
                return cur;
            }

            else{
                // 2.5 左右都不空，左右孩子都可以作为爸爸的新孩子；if左，就把右塞到左的最右（最大）；if右，就把左塞到右的最左（最小）
                TreeNode* cur=root->right; //找右孩子的最左
                while(cur->left!=nullptr){
                    cur=cur->left;
                }
                // 塞左孩子到右孩子的最左
                cur->left=root->left;
                TreeNode* tmp=root;
                
                // // 这样写就不行！
                // delete root;
                // return tmp->right;//此时root已经被删了，root->right没有东西了
                

                // // 这样写也不行！！
                // tmp=tmp->right;
                // delete root;
                // return tmp;

                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        // 3 单层 "中"已经在2处理了， 所以就左右无所谓
        // 用bst性质，往哪里搜索
        if(root->val>key) root->left=deleteNode(root->left,key); // 把左边的全部套娃更新
        if(root->val<key) root->right=deleteNode(root->right,key); //大了，把右边的全部套娃更新
        return root;
    }
};