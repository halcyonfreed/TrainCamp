# 代码随想录——算法训练营DAY20
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 654.最大二叉树 

 

又是构造二叉树，昨天大家刚刚做完 中序后序确定二叉树，今天做这个 应该会容易一些， 先看视频，好好体会一下 为什么构造二叉树都是 前序遍历 

 

题目链接/文章讲解：[https://programmercarl.com/0654.%E6%9C%80%E5%A4%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0654.最大二叉树.html) 

视频讲解：https://www.bilibili.com/video/BV1MG411G7ox



### 类别



### 易错点

1. 在 C++ 中，可以使用 `vector` 的 `begin()` 和 `end()` 方法来指定一个起始和终止位置来取出一个区间。 python不一样

   ` vector<int> sub2(nums.begin() + 3, nums.begin() + 6);`

2. 左闭右开

3. 前序递归

其他:

### code

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node= new TreeNode(0);//用来遍历

        // 结束条件
        if(nums.size()==1) {
            node->val=nums[0]; //改val值
            return node;
        } // 遍历玩了，叶子

        // 开始递归
        // 先找到最大，然后更新中间值
        int maxValue=0;
        int index=0; //要记录下标，不然没法分割区间
        for (int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue=nums[i];
                index=i;
            }
        }
        node->val=maxValue;

        // 左
        // 同时满足终止条件
        if(index>0){
            // node->left=constructMaximumBinaryTree(nums[:index]); //这是python的写法！！！
            vector<int> newvec(nums.begin(),nums.begin()+index); // 默认左闭右开
            node->left=constructMaximumBinaryTree(newvec);
        }

        // 右
        if(nums.size()-index>1){
            // node->right=constructMaximumBinaryTree(nums[index+1:]);
            vector<int> newvec(nums.begin()+index+1,nums.end());
            node->right=constructMaximumBinaryTree(newvec);
        }
        return node;
    }
};


```

简化版没仔细看！！！

1. 每次还要切割的时候每次都要定义新的vector（也就是数组），但逻辑比较清晰。直接在原数组索引

2. 可以发现上面的代码看上去简洁一些，**主要是因为第二版其实是允许空节点进入递归，所以不用在递归的时候加判断节点是否为空**

   ```cpp
   // 另外构造自定义的递归函数
   class Solution{
   private:
       TreeNode* traversal(vector<int>& nums, int left, int right){
           if (left>=right)  return nullptr; // end条件
           
           // 找最大，更新
           int maxValueIndex=left;
           for(int i=left+1; i<right;++i){
               if(nums[i]>nums[maxValueIndex]) maxValueIndex=i;
           }
           TreeNode* root=new TreeNode(nums[maxValueIndex]);
   
           // 左闭右开：[left, maxValueIndex)
           root->left = traversal(nums, left, maxValueIndex);
   
           // 左闭右开：[maxValueIndex + 1, right)
           root->right = traversal(nums, maxValueIndex + 1, right);
   
           return root;
       }
   public:
       TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
           return traversal(nums, 0, nums.size());
       }
   };
   ```

   



## LC 617.合并二叉树 

 

这次是一起操作两个二叉树了， 估计大家也没一起操作过两个二叉树，也不知道该如何一起操作，可以看视频先理解一下。 优先掌握递归。

 

题目链接/文章讲解：[https://programmercarl.com/0617.%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91.html](https://programmercarl.com/0617.合并二叉树.html) 

视频讲解：https://www.bilibili.com/video/BV1m14y1Y7JK



### 类别



### 易错点

1. 

其他:

### code



## LC 700.二叉搜索树中的搜索 

 

递归和迭代 都可以掌握以下，因为本题比较简单， 了解一下 二叉搜索树的特性

 

题目链接/文章讲解: [https://programmercarl.com/0700.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%90%9C%E7%B4%A2.html](https://programmercarl.com/0700.二叉搜索树中的搜索.html) 

视频讲解：https://www.bilibili.com/video/BV1wG411g7sF



### 类别



### 易错点

1. 

其他:

### code



## LC 98.验证二叉搜索树 

 

遇到 搜索树，一定想着中序遍历，这样才能利用上特性。

 

但本题是有陷阱的，可以自己先做一做，然后在看题解，看看自己是不是掉陷阱里了。这样理解的更深刻。

 

题目链接/文章讲解：[https://programmercarl.com/0098.%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html](https://programmercarl.com/0098.验证二叉搜索树.html) 

视频讲解：https://www.bilibili.com/video/BV18P411n7Q4 



### 类别



### 易错点

1. 

其他:

### code