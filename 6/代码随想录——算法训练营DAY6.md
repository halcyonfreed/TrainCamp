# 代码随想录——算法训练营DAY6

2024/1/18补 一定要看文字版！！

不会语法 代码块的问gpt

一道题大概1h

## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 双指针 or 前缀和

双指针：字符串、数组 原地删除/查询

prefix sum： 查询区间的和

也许没有那么热爱，但是当你在同一件事情上付出了足够多的时间，事物的客观规律告诉你，一定会有反馈，不然不科学，这与多努力多热爱无关，懂了吗小朋友，

这是一条正确的道路，值得付出时间，哪怕钱很少，但是有进步

## 哈希

建议：大家要了解哈希表的内部实现原理，**哈希函数，哈希碰撞**，以及常见**哈希表**的区别，数组，set 和map。 

1. 类似dict: {Key: value}. 常见是**三种数据结构：**array，set， map（dict）
2. 什么时候想到用哈希法，**当我们遇到了要快速判断一个元素是否出现集合里的时候（或者元素在集合里出现了几次），就要考虑哈希法**。 这句话很重要，大家在做哈希表题目都要思考这句话。用来**快速判断个元素是否出现在集合里过！！！**：当要判断元素在集合内，第一时间想到用hash法

牺牲了空间换取了时间，因为我们要使额外的数组，set或者是map来存放数据，才能实现快速的查找。

1. 要枚举的话时间复杂度是O(n)因为一个for 所以是O(n)，但如果使.哈希表的话， 只需要O(1)就可以做

2. 1. 哈希函数: x映射到y，把学⽣的姓名直接映射为哈希表上的索引

   2. 哈希碰撞: 多个x映射到一个y

       线性探测法                    确保y长度大于x    
       
       拉链法                     同个y对应多个x   


看网站说明，array  set map  **理论基础看pdf！！！**





**自己总结😈：**

1. hash table: 就是key:value 用key来查询value （不可以修改）
2. hash function：建立实体（真实世界的一个东西）——哈希表的key之间的映射关系，同时key对应value（被存的值）
3. hash collisions：不同实体，映射到同一个key



1. 数组 不讲了
2. set：
   1. set multiset(set和multiset一样，除了set不可重复，multiset可以；红黑树，key值有序，所以不可修改只增删，O(logn)) 
   2. unordered set (hash table; O(1) 无序，也不可以修改)。   记忆方法：各种特性都与底底层实现有关！！！
3. map：和set类似
   1. map
   2. multimap：和map都一样除了key可以重复；底层红黑树，红黑树是二叉平衡树，所以key有序；O(logn)；key 不可以修改，只能增删
   3. unordered_map： hash table；key无序无重复；key不可修改，只能增删；O(1)

## LC 242.有效的字母异位词 

建议： 这道题目，大家可以感受到 数组 用来做哈希表 给我们带来的遍历之处。 

题目链接/文章讲解/视频讲解： [https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html](https://programmercarl.com/0242.有效的字母异位词.html)

### 类别

hash：元素在集合里出现了几次；

数组：元素连续+固定（确定不超过26，而且连续）

### 易错点

1. 为什么用数组：当出现的实体数量是有限固定的，这里确定只会不超过26，那就用hash数组，而且因为数组内存地址连续，字符a到字符z的ASCII也是26个连续的数值。所以不用set，map，就用数组：下标代替字母了，**字符a映射为下标0，相应的字符z映射为下标25**，你学废了吗，小朋友！！！😊
2. 为什么不s，t分别统计出现次数，然后比较==: 这样浪费空间，搞两个数组。很妙，一个加一个减都在一个数组，你学废了吗，小朋友！！！😊

其他:

### code

```cpp
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t){
        // 确定会有多少长度 长26, 元素0
        int cnt[26]={0};
        // 统计次数
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']+=1;
        }
        for(int i=0;i<t.size();i++){
            cnt[t[i]-'a']-=1;
        }
        for(int i=0; i<26;i++){
           cout<<cnt[i]; 
        }
        cout<<endl;
        // 判断，有0就停 用c++11特性
        for(int i=0; i<26;i++){
            if (cnt[i]!=0) return false;
        }
        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().isAnagram(s,t)<<endl;
    return 0;
}
```



## LC 349. 两个数组的交集 

建议：本题就开始考虑 什么时候用set 什么时候用数组，本题其实是使用set的好题，但是后来力扣改了题目描述和 测试用例，添加了 0 <= nums1[i], nums2[i] <= 1000 条件，所以使用数组也可以了，不过建议大家忽略这个条件。 尝试去使用set。 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html](https://programmercarl.com/0349.两个数组的交集.html) 

### 类别



### 易错点

1. 用hash：因为判断里面有什么元素，元素存在集合中吗？
2. 用set：因为无重复（所以不是multiset），而且不连续（无法用数组）；用unordered_set效率最高！#include <unordered_set>
3. **初始化unordered_set**：unordered_set<int> result_set
4. 把一个**vector去重变成unordered_set**：unordered_set<int> nums_set(nums1.begin(), nums1.end())
5. C++11特性：for (int num : nums2)
6. unordered_set.**`.end()`迭代器将指向unordered_set的末尾之后的位置。它并不指向最后一个元素本身，而是指向超过最后一个元素的位置。**
7. unordered_set.find(被找元素)：返回一个迭代器iterator，指向 `std::unordered_set` 中与给定值匹配的元素。如果找到了匹配的元素，则返回指向该元素的迭代器；如果未找到匹配的元素，则返回指向 `std::unordered_set` 结尾的迭代器（即 .`end()` 迭代器）。
8. unordered_set.insert(插入元素)无序的  vector.push_back()有顺序
9. vector<int>(result_set.begin(),result_set.end()) **set变vector**

### C++ 迭代器 iterator

是一种用于遍历容器（如 `std::vector`、`std::list`、`std::unordered_set` 等）中元素的对象。它**类似于指针**，可以**指向容器中的某个元素**，让我们可以通过它来访问或修改元素。

**每种容器都有其自己的迭代器类型**，例如，`std::vector` 有一个叫做 `std::vector<T>::iterator` 的迭代器类型

```cpp
std::vector<int> myVector = {1, 2, 3, 4, 5};

for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
    std::cout << *it << " ";  // 输出当前元素的值
}
```

### code

```cpp
#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 存交集结果
        unordered_set<int> result_set; // 无重复的
        // 先对1去重
        unordered_set<int> num_set(nums1.begin(),nums1.end()); // vector变set
        // 2和去重后的1比较，往结果加
        for(int num:nums2){
            if(num_set.find(num)!=num_set.end()){
                // num_set.find(num)如果没找到就会返回.end()，找到就返回指向元素的iterator
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(),result_set.end());
    }
};
int main(){
    // 输入
    int num1,num2;
    vector<int> nums1, nums2;
    while(cin>>num1){
        nums1.push_back(num1);
        if (getchar()=='\n') break;
    }
    while(cin>>num2){
        nums2.push_back(num2);
        if (getchar()=='\n') break;
    }

    vector<int> result;
    result=Solution().intersection(nums1,nums2);

    // 输出
    for(int num:result){
        cout<<num<<' ';
    }
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<' ';
    // }
    cout<<endl;
    return 0;
}
```



## LC 202. 快乐数  

建议：这道题目也是set的应用，其实和上一题差不多，就是 套在快乐数一个壳子 

题目链接/文章讲解：[https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html](https://programmercarl.com/0202.快乐数.html) 

### 类别



### 易错点

1. why hash set: 

   1. 用set因为要无重复
   2. why hash：因为后面查询在set里出现过sum吗？**快速判断一个元素是否出现集合里的时候，就要考虑哈希法了**

2. 这个想不到：这个sum是否重复出现，如果重复了就是return false， 否则一直找到sum为1为止

3. **求和的过程，如果对取数值各个位上的单数操作不熟悉的话**  这个不太会！ 先求个位 再整除

   ```cpp
   #include<iostream>
   using namespace std;
   int main(){
       cout<<5/10<<endl;
       cout<<4/10<<endl;
       cout<<4.0/10<<endl;
       return 0;
   }
   ```

   结果

   ```
   向下取整，没有四舍五入
   0
   0
   0.4
   ```

   

其他:

### code

```cpp


#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int getSum(int n){
        // 请熟练掌握！！！
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10); //从右往左取
            n/=10; //取下一位
        }
        return sum;
    }
    bool isHappy(int n){
        // hash set存sum
        unordered_set<int> result;



        // 更新set，同时查询
        while(1){
            // 养成习惯，先写body，再写while终止条件
            // 这里因为循环次数不定，所以while，终止条件为什么1，没有，因为可能无限循环，一直算下去所以1就是true
            int sum = getSum(n); //放里面，因为要一直求
            if (sum ==1) return true;
            if(result.find(sum)!=result.end()) return false; // 如果出现过，就停
            else result.insert(sum); //unordered_set用insert；vector用push_back

            n=sum;//一直求新的sum 更新n妙啊！！！ 
        }
    }
};
int main(){
    int n;
    cin>>n;
    cout<<Solution().isHappy(n)<<endl;
    return 0;
}
```



## LC 1. 两数之和 

建议：本题虽然是 力扣第一题，但是还是挺难的，也是 代码随想录中 数组，set之后，使用map解决哈希问题的第一题。

建议大家先看视频讲解，然后尝试自己写代码，在看文章讲解，加深印象。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html](https://programmercarl.com/0001.两数之和.html)

### 类别

hash map；key value存什么！！！

### c++

`pair<int,int>` 是 C++ STL 中的一个模板类，表示一个由两个元素组成的有序对。

`auto iter=map.find(target-nums[i]); ` auto自动推导变量的类型 返回一个std::unordered_map<int,int>::iterator迭代器类型

`std::vector<int> vec1 = {1, 2, 3, 4};`

**map的iterator就是位置类似指针，来访问key，value**，不可以直接map->first!!!!!!!;  要用iter->second 是value

### 易错点

自然暴力法的思路：一个个遍历，先存当前遍历的，然后匹配后面所有的 有就停，没有就把当前弹出 O(n2)



太妙了，和正常的思维根本不一样根本想不到啊啊啊啊：用hash map:

[3,4,5] target=9

i=0  3 查询9-3 没有所以{3:0}  不要担心后面会再查3的

i=1 4 查询9-4  没有5所以{3:0, 4:1}

i=2 5 查询9-5=4 有所以返回下标{1，5} //不要担心为什么直接跳过4了开始查5了，因为查5的时候，会往前查的，这是map特性！！！





1. why map:存结果：**key是元素不是下标！！！！（很容易错啊啊啊啊啊）**；用key元素查询存在过吗；如果存在取value：下标值（被返回的量）数组中同一个元素在答案里不能重复出现；key不用有序，不重复，所以Unordered_map
2. why hash：存当前
3. 很难理解：因为
   1. 一边查询，一边更新
   2. 一旦找不到匹配的，就跳到下一个再查；不担心找不到，因为查后面的时候会倒过来查前面已经遍历过的！！

其他: 

### code

```cpp
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map; //存储访问过的元素及其下标
        for(int i=0; i<nums.size();i++){
            auto iter=map.find(target-nums[i]); 
            //auto自动推导变量的类型 返回一个std::unordered_map<int,int>::iterator迭代器类型
            // 比如nums[0]=2; 找7有吗，如果找到了这里是7，返回7对应的second是值就是下标！！
            if(iter!=map.end()) return {iter->second,i};
            

            map.insert(pair<int,int>(nums[i],i)); //没找到配对的，就把访问过的元素和下标放进去
            // pair<int,int> 是 C++ STL 中的一个模板类，表示一个由两个元素组成的有序对。
        }
        return {}; //没有
    }
};
```

