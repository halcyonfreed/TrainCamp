# 代码随想录——算法训练营DAY2
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 哈希

建议：大家要了解哈希表的内部实现原理，哈希函数，哈希碰撞，以及常见哈希表的区别，数组，set 和map。 

1. 类似dict: {Key: value}. 常见是**三种数据结构：**array，set， map（dict）
2. 什么时候想到用哈希法，**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法**。 这句话很重要，大家在做哈希表题目都要思考这句话。用来**快速判断个元素是否出现在集合里过！！！**：当要判断元素在集合内，第一时间想到用hash法

牺牲了空间换取了时间，因为我们要使额外的数组，set或者是map来存放数据，才能实现快速的查找。

1. 要枚举的话时间复杂度是O(n)因为一个for 所以是O(n)，但如果使.哈希表的话， 只需要O(1)就可以做

2. 1. 哈希函数: x映射到y，把学⽣的姓名直接映射为哈希表上的索引

   2. 哈希碰撞: 多个x映射到一个y

       线性探测法                    确保y长度大于x    

3. ​         拉链法                     同个y对应多个x    



看网站说明，array  set map   

**理论基础看pdf！！！**

## LC 242.有效的字母异位词 

建议： 这道题目，大家可以感受到 数组 用来做哈希表 给我们带来的遍历之处。 

题目链接/文章讲解/视频讲解： [https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html](https://programmercarl.com/0242.有效的字母异位词.html)

### 类别



### 易错点

1. 

其他:

### code

## LC 349. 两个数组的交集 

建议：本题就开始考虑 什么时候用set 什么时候用数组，本题其实是使用set的好题，但是后来力扣改了题目描述和 测试用例，添加了 0 <= nums1[i], nums2[i] <= 1000 条件，所以使用数组也可以了，不过建议大家忽略这个条件。 尝试去使用set。 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html](https://programmercarl.com/0349.两个数组的交集.html) 

### 类别



### 易错点

1. 

其他:

### code

## LC 202. 快乐数  

建议：这道题目也是set的应用，其实和上一题差不多，就是 套在快乐数一个壳子 

题目链接/文章讲解：[https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html](https://programmercarl.com/0202.快乐数.html) 

### 类别



### 易错点

1. 

其他:

### code

## LC 1. 两数之和 

建议：本题虽然是 力扣第一题，但是还是挺难的，也是 代码随想录中 数组，set之后，使用map解决哈希问题的第一题。

建议大家先看视频讲解，然后尝试自己写代码，在看文章讲解，加深印象。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html](https://programmercarl.com/0001.两数之和.html)

### 类别



### 易错点

1. 

其他:

### code