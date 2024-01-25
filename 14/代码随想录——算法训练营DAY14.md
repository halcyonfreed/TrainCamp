# 代码随想录——算法训练营DAY14
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## 链表基础

需要了解 

1. 二叉树的种类：满二叉树（定义，深度和节点数）、完全二叉树（定义：最后一层从左到右连续）

   **优先级队列其实是一个堆，堆就是一棵完全二叉树**

2. 二叉搜索树：**有序树**（左<中<右）;平衡二叉搜索树：又被称为AVL（Adelson-Velsky and Landis）树, 高度差<=1

   **map、set、multimap，multiset的底层实现都是平衡二叉搜索树**，所以logn

   unordered_map、unordered_set底层实现是哈希表

3. 存储方式

   1. 顺序存储的方式就是用数组：下标是序号，父i，左孩子2i+1，右孩子2i+2
   2. 链式存储方式就用指针： 左右指针不难（想成进阶版链表）

4. 遍历方式

   一般喜欢用递归

   1. 深度优先遍历DFS：先往深走，遇到叶子节点再往回走。

      ​	看**“中”**在哪里就是哪个遍历

      1. 前序遍历（递归法，迭代法）**中**左右
      2. 中序遍历（递归法，迭代法）左**中**右
      3. 后序遍历（递归法，迭代法）左右**中**

   2. 广度优先遍历BFS：一层一层的去遍历。

      1. 层次遍历（迭代法）：用队列实现

5. 二叉树的定义 

   类似链表，**在现场面试的时候 面试官可能要求手写代码，所以数据结构的定义以及简单逻辑的代码一定要锻炼白纸写出来**

   ```cpp
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}  //这里是一个构造函数，没有; 加分号代表一条空语句
   };
   ```

6. 构造函数（Constructor）和析构函数（Destructor）

   用于创建和销毁对象的特殊成员函数。

   **构造函数**是在创建对象时被调用的函数。它用于**初始化对象的成员变量**，为对象分配内存，并执行其他必要的初始化操作。构造函数的名称与类名称相同，没有返回类型，并可以带有参数。当使用关键字`new`创建对象时，构造函数会被自动调用。

   例如，下面是一个简单的构造函数的示例：

   ```cpp
   class MyClass {
   public:
       MyClass() {
           // 构造函数的代码逻辑
       }
   };
   ```

   **析构函数**是在**对象销毁时被调用的函数。它用于释放对象所占用的资源，**清理对象状态，并执行其他必要的清理操作。**析构函数的名称与类名称相同，前面加上波浪号（~）**，没有返回类型，且不带参数。

   例如，下面是一个简单的析构函数的示例：

   ```cpp
   class MyClass {
   public:
       ~MyClass() {
           // 析构函数的代码逻辑
       }
   };
   ```

   当对象超出其作用域、被删除或程序终止时，析构函数会被自动调用。通过析构函数，可以确保对象的资源得到正确释放，避免内存泄漏和其他资源相关的问题。

文章讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html](https://programmercarl.com/二叉树理论基础.html) 

## LC 递归遍历 （必须掌握）

二叉树的三种递归遍历掌握其规律后，其实很简单 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html](https://programmercarl.com/二叉树的递归遍历.html) 

- [144.二叉树的前序遍历(opens new window)](https://leetcode.cn/problems/binary-tree-preorder-traversal/)
- [145.二叉树的后序遍历(opens new window)](https://leetcode.cn/problems/binary-tree-postorder-traversal/)
- [94.二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

### 类别

递归；二叉树；链表

### 易错点

#### 递归三要素

1. **确定递归函数的参数和返回值：** 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2. **确定终止条件：**stackoverflation
3. **确定单层递归的逻辑：** 

这里二叉树就是个链表的输入输出比较难，还没搞！！

1.  单层遍历干两件事：遍历链表，把节点加到结果里！！！！！！！！　递归可以同时干两件事，迭代不行，或者要操作加NULL才行，很呆

其他:

### code

```cpp
#include<vector>
// 前序
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){} //没有分号！！！，加分号是空语句
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left, TreeNode* right): val(x),left(left),right(right){}
};

class Solution{
public:
    void traversal(TreeNode* cur,vector<int>& result){
        // 终止条件
        if(cur==NULL) return;
        // 单层逻辑，中左右
        result.push_back(cur->val);
        traversal(cur->left,result);
        traversal(cur->right,result);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};

// 这里的链表的输入输出比较难，还没搞！！
```



中

```cpp
class Solution{
public:
    void traversal(TreeNode* cur, vector<int>& result){
        // 单层遍历干两件事： 遍历； 加入结果
        if(cur==NULL) return;
        // 中序，左中右
        traversal(cur->left,result);
        result.push_back(cur->val);
        traversal(cur->right,result);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};
```



后

```cpp

class Solution{
public:
    void traversal(TreeNode* cur,vector<int>& result){
        if(cur==NULL) return;
        // 左右中
        traversal(cur->left,result);//左
        traversal(cur->right,result); //右
        result.push_back(cur->val); //中
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};
```



## LC 迭代遍历 （基础不好的录友，迭代法可以放过）

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html](https://programmercarl.com/二叉树的迭代遍历.html) 

### 类别

[匹配问题都是栈的强项](https://programmercarl.com/1047.删除字符串中的所有相邻重复项.html)

这里为什么不用队列，用栈

中序不太会还是，前后序可以的

### 易错点

1. st.push() 
2. vector.push_back

**空节点不入栈** 

1. 前：中左右 

2. 后：太妙了：就是前序的结果reverese 好聪明啊；但是左右顺序也要再倒一下！！

   1. 不可以直接，因为reverse返回指针！

      ```cpp
      return reverse(result.begin(),result.end());
      ```

      

3. 中：左右中，因为遍历肯定先中，但是要先找到左叶子

其他:

### code

前

```cpp
// 前序  中左右
// 迭代法，用的是栈：所以是中右左压入，中左右弹出
#include<stack>
#include<vector>
using namesapce std;

class Solution{
public:
    vector<int> preorderTraversal(TreedNode* root){
        stack<TreeNode*> st; //遍历节点
        vector<int> result;

        if(root==NULL) return result; //特殊情况，如果本来就是空的树，就返回空

        st.push(root); //初始化压入
        while(!st.empty()){
            // 弹出顶,
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val); //遇到中间，先弹中间，再压右和左
            if(node->right) st.push(node->right); //if会忘！！！
            if(node->left) st.push(node->left);
        }
        return result;
    }
};
```

中

```cpp
// 中序最难！！  左中右，不能先压，要先找到左才压
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; //存遍历的node
        vector<int> result; //存result
        TreeNode* cur=root; //用来遍历


        // 次数不定用while
        while(cur!=NULL || !st.empty()){
            // 非叶子节点，或者非空！
            // 最后写条件！
            if(cur!=NULL){//一路只往左，直到访问到最底层左叶子
                st.push(cur);
                cur=cur->left;
            }else{
                cur=st.top();
                st.pop();
                result.push_back(cur->val);//中

                cur=cur->right;//右
            }
        }
        return result;
    }
};
```

后

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
    // void traversal(TreeNode* cur,vector<int>& result){
    //     if(cur==NULL) return;
    //     // 左右中
    //     traversal(cur->left,result);//左
    //     traversal(cur->right,result); //右
    //     result.push_back(cur->val); //中
    // }

    // vector<int> postorderTraversal(TreeNode* root){
    //     vector<int> result;
    //     traversal(root,result);
    //     return result;
    // }

    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st; //遍历 元素是node=val+指针
        vector<int> result; //存结果

        if(root==NULL) return result; //特殊情况
        st.push(root);

        while(!st.empty()){
            TreeNode* cur=st.top();
            st.pop();//先取再删！！

            result.push_back(cur->val); //压入结果
            
            //这里也要改顺序，为什么，因为最后reverse了，所以这里左右也要改
            
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
```



## LC 统一迭代  （基础不好的录友，迭代法可以放过）

这是统一迭代法的写法， 如果学有余力，可以掌握一下   



跳过了，普通的迭代掌握了，这个太烦了，粗略看了一下，没看懂，有点多此一举的感觉，正经人谁这么干！！！

题目链接/文章讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html](https://programmercarl.com/二叉树的统一迭代法.html)

### 类别



### 易错点

1. 

其他:

### code