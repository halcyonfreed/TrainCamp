# 代码随想录——算法训练营DAY17

先做题，然后写笔记 day22的时候补完17

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

 

这是大家第一次接触到回溯的过程， 我在视频里重点讲解了 本题为什么要有回溯，已经回溯的过程。 

 

如果对回溯 似懂非懂，没关系， 可以先有个印象。 

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html](https://programmercarl.com/0257.二叉树的所有路径.html)

### 类别

没看拓展版递归+迭代法

找路径的题，都要回溯：前序递归+回溯！

to_string(int类型)

vector.push_back()  .pop_back()

vector.end()返回的是指向最后一个位置下一个的位置的指针

### 易错点

1. 递归三部曲

   1. 返回空，直接一直更新；传入node，path，result（string版本的path）在函数参数列表中，&符号表示将参数按引用传递。
   2. 终止条件：不是cur=null因为只要下一层是叶子就可以操作了，不是自己是叶子才停止。终止以后转成string path
   3. 前序，中放的位置，要放在终止条件之前！！！！

2. **那么为什么使用了vector 结构来记录路径呢？** 因为在下面处理单层递归逻辑的时候，要做回溯，使用vector方便来做回溯

3. **回溯和递归是一一对应的，有一个递归，就要有一个回溯**，这么写的话相当于把递归和回溯拆开了， 一个在花括号里，一个在花括号外。

   **所以回溯要和递归永远在一起，世界上最遥远的距离是你在花括号里，而我在花括号外！**

   就是套娃一次，就要回溯回去一次！！！！！！！！！

其他:

### code

```cpp
class Solution {
private:
    void traversal(TreeNode* node, vector<int>& path, vector<string>& result){
        path.push_back(node->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
        // 前序
        // 2 终止条件，下一层孩子是叶子
        string spath;
        if(node->left==nullptr && node->right==nullptr){
            // for(int i=0;i<path.size()-1;++i){
            //     result.push_back(to_string(path[i]));
            //     result.push_back("->");
            // }
            // result.push_back(to_string(path[path.size()-1]));  //["1","->","2","1"]
            // string spath;
            for(int i=0;i<path.size()-1;++i){
                spath+=to_string(path[i]); //不可以写=  是+=
                spath+="->";
            }
            spath+=to_string(path[path.size()-1]);
            result.push_back(spath);
        }

        // 3 前序 中左右; 套娃
        // path.push_back(node->val);  //中放这里最后一个进不去，最后一个叶子就压不进去了，为什么，要放在终止条件之前
        // 先判非空,回溯要在{}内！！
        if(node->left){
            traversal(node->left,path,result);
            path.pop_back();
        }
        if(node->right){
            traversal(node->right,path,result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root==nullptr) return result;//忘记特殊情况
        traversal(root,path,result);
        return result;
    }
};
```



## LC 404.左叶子之和 （优先掌握递归）

 

其实本题有点文字游戏，搞清楚什么是左叶子，剩下的就是二叉树的基本操作。

 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0404.%E5%B7%A6%E5%8F%B6%E5%AD%90%E4%B9%8B%E5%92%8C.html](https://programmercarl.com/0404.左叶子之和.html) 



### 类别

**平时我们解二叉树的题目时，已经习惯了通过节点的左右孩子判断本节点的属性（用下一层判断这一层），而本题我们要通过节点的父节点判断本节点的属性（通过爸爸上一层判断这一层孩子）。**

### 易错点

1. 后序：因为叶子之和，所以从下到上就是后序，从叶子到根，后序遍历（左右中），是因为要通过递归函数的返回值来累加求取左叶子数值之和

2. 终止有两个：自己是叶子停， 孩子是叶子（左右孩子都空）也停！！！ body：左叶子之和必然0

   只有当前遍历的节点是父节点，才能判断其子节点是不是左叶子。 所以如果当前遍历的节点是叶子节点，那其左叶子也必定是

3. 左（判完左，leftsum这里有点混乱！！！）右中

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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 1 就用题给的
        // 2 终止条件
        if (root==nullptr) return 0;//自己是空的，左孩子之和一定是0
        if (root->left==nullptr && root->right==nullptr) return 0; //下一层是空，所以自己是叶子，所以左孩子之和是0

        int result;

        // 3 叶子 左右中，从下往上累加
        int leftSum=sumOfLeftLeaves(root->left); //一般情况，正常套娃就行，下面这种需要算leftsum！！
        if(root->left && !root->left->left&& !root->left->right){
            leftSum=root->left->val;//左孩子是叶子，就是左孩子的下一层都是空的，则左孩子自己是叶子！
        } 

        int rightSum=sumOfLeftLeaves(root->right);
        result=leftSum+rightSum;
        return result;
    }
};
```

