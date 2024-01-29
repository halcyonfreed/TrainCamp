# 代码随想录——算法训练营DAY
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

 

迭代法，大家可以直接过，二刷有精力的时候 再去掌握迭代法。!!



## LC  110.平衡二叉树 （优先掌握递归）

再一次涉及到，什么是高度 从下往上后序，什么是深度 从上往下 前序，可以巩固一下。 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0110.平衡二叉树.html)



### 类别

求深度从上往下适合用前序遍历，而求高度从下往上适合用后序遍历。

本题迭代法其实有点复杂，大家可以有一个思路，也不一定说非要写出来。

但是递归方式是一定要掌握的！

### 易错点

1. 不难就是要想清楚，怎么构造递归，递归用来求高度
2. main函数用来判断
3. -1不好想

其他:

### code

```cpp
class Solution {
private:
    int getHeight(TreeNode* node){
        if(node==nullptr) return 0;
        // 后序，求高度左右中
        // int leftHeight=getHeight(node->left);
        // int rightHeight=getHeight(node->right);
        // return 1+max(leftHeight,rightHeight);
        
        int leftHeight=getHeight(node->left);
        if (leftHeight==-1) return -1;
        int rightHeight=getHeight(node->right);
        if (rightHeight==-1) return -1;
        return abs(leftHeight-rightHeight)>1?-1:1+max(leftHeight,rightHeight);
    } //无分号
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1? false:true;
    }
};
```



## LC 257. 二叉树的所有路径 （优先掌握递归） 

 

这是大家第一次接触到回溯的过程， 我在视频里重点讲解了 本题为什么要有回溯，已经[[1\]](#_msocom_1) 回溯的过程。 

 

如果对回溯 似懂非懂，没关系， 可以先有个印象。 

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html](https://programmercarl.com/0257.二叉树的所有路径.html)

### 类别

找路径的题，都要回溯：前序递归+回溯！

### 易错点

1. 

其他:

### code



## LC 404.左叶子之和 （优先掌握递归）

 

其实本题有点文字游戏，搞清楚什么是左叶子，剩下的就是二叉树的基本操作。

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0404.%E5%B7%A6%E5%8F%B6%E5%AD%90%E4%B9%8B%E5%92%8C.html](https://programmercarl.com/0404.左叶子之和.html) 



### 类别



### 易错点

1. 

其他:

### code