# 代码随想录——算法训练营DAY1
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 704 二分查找

题目链接：[LC 704 二分查找](https://leetcode.cn/problems/binary-search/)
文章讲解：https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html
视频讲解：https://www.bilibili.com/video/BV1fA4y1o715

### 类别

double ptr；二分法

### 易错点

1. left, right初始值
2. while 里 left 与 right 可以取==?
3. 如何更新left right

其他：防止溢出, 没有直接(right+left)/2，   mid = left + (right - left) / 2

### 左闭右开[)

具体解释看代码，这里只是题纲，用来回忆

1. right = nums.size();
2.  while (left < right)
3. right = mid，left = mid + 1

### 左闭右闭[]

1. right = nums.size()-1;
2.  while (left < = right)
3. right = mid-1，left = mid + 1

### ACM模式读入vector

```cpp
 vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }
```

### ACM实现并输出类

```cpp
cout<< Solution().search(nums,target) << ' ' << Solution2().search(nums,target) << endl;
```

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
    class Solution{
    public:
        int search(vector<int>& nums, int target){
            // [) 左闭右开，所以右取不到
            int left = 0, right = nums.size();
            // 当left== right，区间[left, right)没效了，所以用 < 
            while (left < right){
                int mid = left + (right - left) / 2; // 防止溢出, 没有直接(right+left)/2
                if (nums[mid] > target){
                    // target 在左半， 动right; 因为[) right取不到，mid已经比过了，所以right= mid
                    right = mid;
                }
                else if (nums[mid] < target){
                    // target在右半
                    left = mid + 1;
                }
                else
                    return mid;
            }
            return -1;   
        }
    };

    class Solution2{
    public:
        int search(vector<int>& nums, int target){
            // [] 左闭右闭，所以右可以取到，所以是-1，如果不减1，根本下标取不到
            int left = 0, right = nums.size() - 1;
            // 这里自己做的时候错了！！！！ 
            // 当left==right，区间[left, right]依然有效，所以用 <= 可以取== 
            while (left <= right){
                int mid = left + (right - left) / 2; // 防止溢出, 没有直接(right+left)/2
                if (nums[mid] > target){
                    // target 在左半， 动right; 因为[] right取得到，mid已经比过了，所以right= mid-1
                    right = mid -1;
                }
                else if (nums[mid] < target){
                    // target在右半
                    left = mid + 1;
                }
                else
                    return mid;
            }
            return -1;   
        }
    };

    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }

    int target;
    cin>>target;

    cout<< Solution().search(nums,target) << ' ' << Solution2().search(nums,target) << endl;
    return 0;
}
```

## ACM模式输入输出参考

[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## LC 27

题目链接：https://leetcode.cn/problems/remove-element/ 

文章讲解：[https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html](https://programmercarl.com/0027.移除元素.html)

视频讲解：https://www.bilibili.com/video/BV12A4y1Z7LP 

 

### 类别

double ptr；fast slow ptr快慢指针

### 易错点

1. fast slow双指针

2. for (int fast = 0; fast <= nums.size()-1; fast++) 不行 nums.size()=0情况 nums=[]

3. for内if内 是谁和谁比，条件写不对

   

### ACM模式读入vector

```cpp
vector<int> nums;
    int num,target;
    while(cin>>num){
        nums.push_back(num);
        if (getchar() == '\n') break;
    }
```

### ACM实现并输出类

```cpp
cout<< Solution().removeElement(nums,target)<<endl;
```

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; 
        // for (int fast = 0; fast <= nums.size()-1; fast++){ //这样写， nums=[] 就会报错，runtime error: reference binding to null pointer of type 'int' (stl_vector.h)； 因为nums.size()此时=0 nums.size()-1=-1就有问题了
        for (int fast = 0; fast < nums.size(); fast++){
            if (val != nums[fast]){
                // 如果不等于,那么不删不跳过,所以赋值； 第一次写错了，把nums[fast]和nums[slow]比，脑子没想清楚谁和谁比！！
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
int main(){
    vector<int> nums;
    int num,target;
    while(cin>>num){
        nums.push_back(num);
        if (getchar() == '\n') break;
    }
    cin>>target;
    cout<< Solution().removeElement(nums,target)<<endl;
    return 0;
}

```