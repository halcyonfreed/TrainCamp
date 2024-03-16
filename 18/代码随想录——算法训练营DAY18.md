# 代码随想录——算法训练营DAY18
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

见手写整理！！

## LC  513.找树左下角的值

本题递归偏难，反而迭代简单属于模板题， 两种方法掌握一下 

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0513.%E6%89%BE%E6%A0%91%E5%B7%A6%E4%B8%8B%E8%A7%92%E7%9A%84%E5%80%BC.html](https://programmercarl.com/0513.找树左下角的值.html) 

### 类别

queue.push()，empty()  .front()

### 易错点

1. 找出树的**最后一行（就是最后一层）的最左边的值**。此时大家应该想起用层序遍历是非常简单的了，反而用递归的话会比较难一点。

其他:

### code

先掌握迭代法 很容易想到层序遍历

```cpp

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
```

递归法：

记录深度（从而找到最后一层）+ 最后一层第一个

```cpp
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
```



## LC 112 路径总和   113. 路径总和ii

本题 又一次要回溯的过程，而且回溯的过程隐藏的还挺深，建议先看视频来理解

  一起做了。 优先掌握递归法。

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.html

### 类别



### 易错点

1. 先草稿纸，输入画出树来！！
2. 要不要return值的问题总结 3大类！！！
3. 技巧：设计累减与0比，不用累加和target sum比！！烦！！！

其他:

### code

```cpp
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
```

113

```cpp

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
```



## LC 106.从中序与后序遍历序列构造二叉树 105.从前序与中序遍历序列构造二叉树

本题算是比较难的二叉树题目了，大家先看视频来理解。

 

106.从中序与后序遍历序列构造二叉树，105.从前序与中序遍历序列构造二叉树 一起做，思路一样的

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0106.从中序与后序遍历序列构造二叉树.html)

### 类别



### 易错点

1. 

其他:

### code