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

其他:

### code





## LC 迭代遍历 （基础不好的录友，迭代法可以放过）

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html](https://programmercarl.com/二叉树的迭代遍历.html) 

### 类别



### 易错点

1. 

其他:

### code



## LC 统一迭代  （基础不好的录友，迭代法可以放过）

这是统一迭代法的写法， 如果学有余力，可以掌握一下 

题目链接/文章讲解：[https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html](https://programmercarl.com/二叉树的统一迭代法.html)



### 类别



### 易错点

1. 

其他:

### code