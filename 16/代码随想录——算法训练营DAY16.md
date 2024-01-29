# 代码随想录——算法训练营DAY16

第六章 二叉树part03

看题目，视频，文字版，自己写一遍

后序：从下往上，从叶子往根，左右中

前序：从上往下，中左右

树非常适合递归：因为中间爸爸的结果=左孩子的结果+右孩子的结果

## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 104.二叉树的最大深度 （优先掌握递归）

什么是深度，什么是高度，如何求深度，如何求高度，这里有关系到二叉树的遍历方式。

大家 要先看视频讲解，就知道以上我说的内容了，很多录友刷过这道题，但理解的还不够。

题目链接/文章讲解/视频讲解： [https://programmercarl.com/0104.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6.html](https://programmercarl.com/0104.二叉树的最大深度.html) 

### 类别

递归法：

​	后序求根节点的高度；

​	真正的求深度看了粗略的，前序，回溯：

迭代法：

​	层序遍历：有点印象，用deque队列记录节点；固定这层的size=que.size()；

​	树的层数=树的高度=根节点的maxDepth

### 易错点

1. 树的深度：从根root node 到任一node的距离 深度是 从上往下 所以中左右 前序
2. 节点的高度：从叶子往上到任一节点，高度是从下往上累加，所以左右中  后序
3. **根节点的高度=树的最大深度！！** 所以此题前后序都可以！

其他:

### code

```cpp

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        // 递归是用套娃代替while，for循环
        int leftDepth=maxDepth(root->left); //左
        int rightDepth=maxDepth(root->right);// 右
        int midDepth=1+max(leftDepth,rightDepth); //中，上一层的爸爸
        return midDepth;
    }
};
```



## LC 111.二叉树的最小深度 （优先掌握递归）

先看视频讲解，和最大深度 看似差不多，其实 差距还挺大，有坑。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.html](https://programmercarl.com/0111.二叉树的最小深度.html)

### 类别



### 易错点

1. 还是转化成求高度：根节点到最近叶子的高度

2. 但是**我就是那个典型错误**第一遍想的时候：**最小深度是从根节点到最近叶子节点的最短路径上的节点数量。**，注意是**叶子节点**。什么是叶子节点，左右孩子都为空的节点才是叶子节点！

3. ```cpp
   int leftDepth = getDepth(node->left);
   int rightDepth = getDepth(node->right);
   int result = 1 + min(leftDepth, rightDepth);
   return result;
   ```

   左右孩子只有一边是空的单独讨论！

其他:

### code

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 2 end
        if(root==nullptr) return 0; //本来就空，停
        // 后序 左右中
        // 左
        int leftDepth=minDepth(root->left);
        // 右
        int rightDepth=minDepth(root->right);
        // 中
        int result;
        // 不对
        // if(root->left && root->right!=nullptr) return 1+rightDepth;
        // else if(root->right && root->left!=nullptr) return 1+leftDepth;
        // else return 1+min(rightDepth,leftDepth);
        
        if(root->left==nullptr && root->right!=nullptr) result=1+rightDepth; 
        else if(root->right==nullptr && root->left!=nullptr) result= 1+leftDepth;
        else result= 1+min(rightDepth,leftDepth);
        
        cout<<result<<endl;
        return result;
    }
};
```



## LC 222.完全二叉树的节点个数（优先掌握递归）

需要了解，普通二叉树 怎么求，完全二叉树又怎么求

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.html](https://programmercarl.com/0222.完全二叉树的节点个数.html)

### 类别

最后一层从左到右连续的！

### 易错点

1. 普通法——递归、迭代层序  自己容易想
2. 用完全二叉树性质：在完全二叉树中，如果递归向左遍历的深度不等于递归向右遍历的深度，则说明不是满二叉树  难想得到！

其他:

### code

递归法：

```cpp
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
```

迭代法模板默写： 用队列记录每一层的节点数，层序遍历

```cpp
queue<TreeNode*> que; // 定义队列，存遍历节点
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
```



```cpp
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
```

性质

```cpp

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
```

