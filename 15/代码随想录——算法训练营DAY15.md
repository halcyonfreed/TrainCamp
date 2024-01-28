# 代码随想录——算法训练营DAY15
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 层序遍历 

看完本篇可以一口气刷十道题，试一试， 层序遍历并不难，大家可以很快刷了十道题。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html](https://programmercarl.com/0102.二叉树的层序遍历.html)

- [102.二叉树的层序遍历(opens new window)](https://leetcode.cn/problems/binary-tree-level-order-traversal/)
- [107.二叉树的层次遍历II(opens new window)](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)
- [199.二叉树的右视图(opens new window)](https://leetcode.cn/problems/binary-tree-right-side-view/)
- [637.二叉树的层平均值(opens new window)](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)
- [429.N叉树的层序遍历(opens new window)](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)
- [515.在每个树行中找最大值(opens new window)](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)
- [116.填充每个节点的下一个右侧节点指针(opens new window)](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)
- [117.填充每个节点的下一个右侧节点指针II(opens new window)](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)
- [104.二叉树的最大深度(opens new window)](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)
- [111.二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

### 类别

1. 为什么用队列
   1. 因为可以记录谁是同一层，每层有几个元素
2. 层序遍历BFS,**队列先进先出，符合一层一层遍历的逻辑**
3. DFS**而用栈先进后出适合模拟深度优先遍历也就是递归的逻辑**

### 易错点

1. 思路：记录每一层的size和元素vec，最后把vec合成result

其他:

### code

102：

```cpp
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
```



## LC 226.翻转二叉树 （优先掌握递归） 

这道题目 一些做过的同学 理解的也不够深入，建议大家先看我的视频讲解，无论做过没做过，都会有很大收获。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0226.翻转二叉树.html) 

### 类别

que.front(), empty(), .pop(), .size()

vector.push_back()

递归：用**调用函数**代替循环；三要素，判断前中后序选一个

迭代：for while思路；用stack存遍历的node

### 易错点

1. 一定掌握递归法：递归的本质使用**调用函数**套娃来代替for，while循环！
2. 迭代法选做吧！！[二叉树：听说递归能做的，栈也能做](https://programmercarl.com/二叉树的迭代遍历.html)迭代法就是for，while循环那种方法！！ 
3. `swap` 需要包含 `<algorithm>` 头文件

其他:

### code

递归法

```cpp
#include<algorithm>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 2 end condition
        if(root==nullptr) return root;
        // 单层logic 前序、后序
        swap(root->left,root->right); //左右孩子换
        invertTree(root->left);    //左子树全换 开始套娃
        invertTree(root->right);
        return root;
    }
};
```



## LC  101. 对称二叉树 （优先掌握递归） 

先看视频讲解，会更容易一些。 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0101.对称二叉树.html) 

### 类别

迭代法没看

递归：终止条件想不清

### 易错点

1. 本身空，左右孩子空，或者不等结束
2. 左右孩子等，就判断下一层开始套娃（外侧和内测，这里是后序遍历，看不清楚这里用到了后序遍历！！）  因为其实没有中,用左右子树返回给上一层的父节点“中”：我们可以看出使用的遍历方式，左子树左右中，右子树右左中，所以我把这个遍历顺序也称之为“后序遍历”（尽管不是严格的后序遍历）

其他:

### code

```cpp
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
class Solution{
public:
    bool compare(TreeNode* left, TreeNode* right){
        // 终止条件，左右子树存在叶子节点了
        if(left==nullptr && right !=nullptr) return false; //左空叶子，右不空
        else if(left!=nullptr && right ==nullptr) return false;
        else if(left==nullptr && right ==nullptr) return true;
        else if(left->val!=right->val) return false;  // 左右都不空

        // 单层逻辑，左右都不空且相同，就判下一层，递归了
        // 后序 左子树左右中，右子树右左中
        
        bool inside= compare(left->right,right->left);//内测，内外侧部分先后顺序都可AC，比左子树的右=右子树的左？
        bool outside= compare(left->left,right->right);//外侧，比左子树的左=右子树的右？
        bool isSame=outside&& inside; // 左子树：中、 右子树：中（逻辑处理）
        return isSame;
    }

    bool isSymmetric(TreeNode* root){
        if(root==nullptr) return true;
        return compare(root->left,root->right);
    }
};
```

