# 代码随想录——算法训练营DAY21
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 530.二叉搜索树的最小绝对差 

 

需要领悟一下二叉树遍历上双指针操作，优先掌握递归

题目链接/文章讲解：[https://programmercarl.com/0530.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE.html](https://programmercarl.com/0530.二叉搜索树的最小绝对差.html) 

视频讲解：https://www.bilibili.com/video/BV1DD4y11779 



### 类别



### 易错点

1. 

其他:

### code



## LC 501.二叉搜索树中的众数 

和 530差不多双指针思路，不过 这里涉及到一个很巧妙的代码技巧。

可以先自己做做看，然后看我的视频讲解。

[https://programmercarl.com/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.html](https://programmercarl.com/0501.二叉搜索树中的众数.html) 

视频讲解：https://www.bilibili.com/video/BV1fD4y117gp



### 类别



### 易错点

1. 

其他:

### code



## LC 236. 二叉树的最近公共祖先 

本题其实是比较难的，可以先看我的视频讲解

[https://programmercarl.com/0236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.html](https://programmercarl.com/0236.二叉树的最近公共祖先.html) 

视频讲解：https://www.bilibili.com/video/BV1jd4y1B7E2  

### 类别



### 易错点

1. 从下到上，用孩子来更新爸爸，所以后序 左右中。
2. 同时要返回到爸爸所以要回溯！！
3. 深度定义
4. 情况1：一般；情况2：一个节点也可以是它自己的祖先
5. 4种分类讨论，好烦 想不清楚的

官方总结

1. 求最小公共祖先，需要从底向上遍历，那么二叉树，只能通过后序遍历（即：回溯）实现从底向上的遍历方式。
2. 在回溯的过程中，必然要遍历整棵二叉树，即使已经找到结果了，依然要把其他节点遍历完，因为要使用递归函数的返回值（也就是代码中的left和right）做逻辑判断。
3. 要理解如果返回值left为空，right不为空为什么要返回right，为什么可以用返回right传给上一层结果。

可以说这里每一步，都是有难度的，都需要对二叉树，递归和回溯有一定的理解

其他:

### code