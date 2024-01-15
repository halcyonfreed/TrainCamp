# 代码随想录——算法训练营DAY2
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 要求：

复习自己默写了一遍ACM模式的DAY1

当天的看了题解，leetcode默一遍，vscode自己再写一遍

## LC 977.有序数组的平方

题目链接：[**https://leetcode.cn/problems/squares-of-a-sorted-array/**](https://leetcode.cn/problems/squares-of-a-sorted-array/)

文章讲解：**https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html**](https://programmercarl.com/0977.有序数组的平方.html)

视频讲解： [**https://www.bilibili.com/video/BV1QB4y1D7ep**](https://www.bilibili.com/video/BV1QB4y1D7ep) 

### 类别

double ptr的左右指针

### 易错点

1. 暴力法：快排的O(nlogn) sort(a.begin(), a.end())
2. 学会看返回类型有提示，虽然考试没提示；自定义一个存结果
3. 想不到双指针，有负数想不到两边平方是最大的，倒序存result
4. for的第二个条件，忘记写分号，因为没有第三个条件； >还是>=
5. ACM模式：
   1. vector不可以直接输出 用while；
   2. 读入vector  `if(getchar()=='\n') break; `放的位置很重要，否则getchar()会使最后一个元素读不进来

### c++语法

get

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 要返回result，自己要设一个vector存result; 从两边开始最大开始更新，递减
        int k = nums.size()-1; // 更新result的下标
        vector<int> result(nums.size(), 0); // vecto初始化不会，确定长度和内容=0
        
        // 定长，用for来遍历
        for(int left=0, right = nums.size() - 1; left <= right;){
            // left=right要处理，所以<=; 第三个分号没写因为要分情况！！ 第二个分号会因为第三个没写漏掉！！
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                // vector已经初始化值了，就不用pushback动脑子，直接改值
                result[k--] = nums[left] * nums[left];
                left++;
            }
            else{
                result[k--] = nums[right] * nums[right];
                right --;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    int num;
    while(cin>> num){
        // if(getchar()=='\n') break; //放这里最后一个元素就读不进来了；getchar不等待回车，直到缓冲区中的字符读完为后，才等待用户按键
        nums.push_back(num);
        if(getchar()=='\n') break; //位置重要
        // cout<< num<<endl;
    }

    // vector不可以直接输出
    // cout << Solution().sortedSquares(nums) <<endl;
    vector<int> result=Solution().sortedSquares(nums);
    // cout<<result.size()<<' '<< nums.size()<<endl;
    for(int i=0; i<nums.size();i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;


    // 测试getchar()
    while(cin>>num){
        // 输入缓冲区，同时num已经从缓冲区里取走了
        cout<<num<<endl;
        cout<< getchar()<<endl;
        cout<<endl;
    }
    return 0;
}
```

## LC 209.长度最小的子数组

 

**题目建议**： 本题关键在于理解滑动窗口，这个滑动窗口看文字讲解 还挺难理解的，建议大家先看视频讲解。 拓展题目可以先不做。 

题目链接：[**https://leetcode.cn/problems/minimum-size-subarray-sum/**](https://leetcode.cn/problems/minimum-size-subarray-sum/)

文章讲解：[**https://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html**](https://programmercarl.com/0209.长度最小的子数组.html)

视频讲解：https://www.bilibili.com/video/BV1tZ4y1q7XE

### 类别

双指针（滑动窗口的起始 结束位置）； 滑动窗口

### 易错点

1. 想思路的核心：想清这些就能搞出来！！
   1. 定义：几个变量存结果，过程量
   2. 要什么循环 for while
      1. 判断条件
      2. 循环内容，里面干几件事
2. sliding window想清楚几件事
   1. 窗口内是什么
   2. 如何移动窗口的起始位置  if sum>s 移 窗口缩小
   3. 如何移动窗口的结束位置？
3. 时间复杂度O(n)不是O(n^2)
4. 一开始设一个超大的数来检测没有找到的情况INT32_MAX, nums.size()+1也可以

其他：为什么不是遍历起始位置，移动结束位置，试一试，终于明白了答案就是我本来的想法：

1. 固定住起始位置i，
2. 然后不断移动结束位置（用for遍历j）
3. 找到合适的就移动起始位置i往后，弹出i！

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int result=nums.size()+1; //就是一个很大的数 用来检测没找到情况！！！ 默认长度
        int result=INT32_MAX;
        int sum=0; // 滑动窗口数值之和
        int i=0; // 滑动窗口起始位置
        int subLength=0; // 滑动窗口的长度

        for(int j=0; j<nums.size();++j){
            sum+=nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件 不是if
            while(sum>=target){
                // 更新minLen
                subLength=j-i+1; 
                result= subLength<result? subLength:result;

                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置），弹出old起始
            }
        }
        // return result==nums.size()+1? 0:result;
        return result==INT32_MAX? 0:result;
    }
};
int main(){
    int num,target;
    vector<int> nums;
    while(cin>>num){
        nums.push_back(num);
        if(getchar() == '\n') break;
    }

    cin>>target;
    cout<<Solution().minSubArrayLen(target,nums)<<endl;
    return 0;
}
```



##  LC 59.螺旋矩阵II

**题目建议**： 本题关键还是在转圈的逻辑，在二分搜索中提到的区间定义，在这里又用上了。  

题目链接：https://leetcode.cn/problems/spiral-matrix-ii/

文章讲解：[https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html](https://programmercarl.com/0059.螺旋矩阵II.html)

视频讲解：https://www.bilibili.com/video/BV1SL4y1N7mV/

### 类别

模拟行为，没什么算法，二维数组遍历，两个for暴力法；左闭右开，没法左闭右闭，会重复！！

## 易错

1. 无从下手，想不到以圈为单位

2. 想不到奇数时，中间要单独处理

3. 不知道设置offset和count

   自己草稿纸上写例子，n=3,4,5都写出来就知道规律了，转几圈，中间怎么处理

4. 不太好，挺卡的做的，边界乱起八糟的，想不到i,j设置模拟过程 比较糊涂

### C++

1. ```
   vector<vector<int>> res(n,vector<int>(n,0));
   ```

   

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n,vector<int>(n,0));

        int startx=0, starty=0;
        int loop=n/2,mid=n/2;

        int count=1;
        int offset=1;
        while(loop--){
            int i,j; //这里和官方不一样
            for(j=starty;j<n-offset;j++){
                res[startx][j]=count++;
            }
            for(i=startx;i<n-offset;i++){
                res[i][j]=count++;
            }
            for(;j>startx;j--){
                res[i][j]=count++;
            }
            for(;i>startx;i--){
                res[i][j]=count++;
            }
            startx++;
            starty++;

            offset++;
        }
        if(n%2) res[mid][mid]=count;
        return res;
    }
};

//官方题解
class Solution2{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        
        // 以圈为单位想问题
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            // 这里很妙的 自己想不清的，i，j是while内全局变量
            i = startx;
            j = starty;
            // 下面开始的四个for就是模拟转了一圈，没办法左闭右闭，这样会重复
            // 模拟填充上行从左到右(左闭右开) 所以最后一个不能取，只能到n-2
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;// j到n-offset-1了最右
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++; //j 最右，i最低了
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;// j最左，i最低
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;//j最左，i最上
            }

            // 左边往里缩，第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // 右边也往里缩！！offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> result;
    result=Solution().generateMatrix(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< result[i][j]<<' ';
            // cout<< Solution().generateMatrix(n)[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

```

