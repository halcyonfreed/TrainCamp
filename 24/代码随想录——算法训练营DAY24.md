# 代码随想录——算法训练营DAY 24
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

20240207补 

## 理论基础 

 

其实在讲解二叉树的时候，就给大家介绍过回溯，这次正式开启回溯算法，大家可以先看视频，对回溯算法有一个整体的了解。

 

题目链接/文章讲解：[https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html](https://programmercarl.com/回溯算法理论基础.html) 

视频讲解：https://www.bilibili.com/video/BV1cy4y167mM 

1. 一种搜索的方式，回溯搜索法，只要有递归就会有回溯
2. 效率低：**本质是穷举，暴力搜索**
3. 解决问题：
   1. 组合问题：N个数里面按一定规则找出k个数的集合  无序，排列有序
   2. 切割问题：一个字符串按一定规则有几种切割方式
   3. 子集问题：一个N个数的集合里有多少符合条件的子集
   4. 排列问题：N个数按一定规则全排列，有几种排列方式
   5. 棋盘问题：N皇后，解数独等等





## LC 77. 组合 + 剪枝

 

对着 在 回溯算法理论基础 给出的 代码模板，来做本题组合问题，大家就会发现 写回溯算法套路。

 

在回溯算法解决实际问题的过程中，大家会有各种疑问，先看视频介绍，基本可以解决大家的疑惑。

 

本题关于剪枝操作是大家要理解的重点，因为后面很多回溯算法解决的题目，都是这个剪枝套路。

 

题目链接/文章讲解：[https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html](https://programmercarl.com/0077.组合.html)  

视频讲解：https://www.bilibili.com/video/BV1ti4y1L7cv 

剪枝操作：https://www.bilibili.com/video/BV1wi4y157er  

 



### 类别



### 易错点

1. 

其他:

### code
