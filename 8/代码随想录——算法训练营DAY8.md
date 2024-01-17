# 代码随想录——算法训练营DAY8

## ACM模式输入输出参考

[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 总结

不只看视频，还要看文字版！！！！文字版的给自己的思考更多！!

### c++11特性

for(int num:nums)

for(char letter: words)

### git报错

ssh:connect to host github.com port 22: Connection timed out

[用的方法二：](https://blog.csdn.net/weixin_45637036/article/details/106560217)

[Git问题：解决“s](https://blog.csdn.net/weixin_45637036/article/details/106560217)

[sh:connect to host github.com port 22: Connection timed out”_ssh: connect to host github.com port 22: connectio-CSDN博客](https://blog.csdn.net/weixin_45637036/article/details/106560217)

## LC 344.反转字符串

建议： 本题是字符串基础题目，就是考察 reverse 函数的实现，同时也明确一下 平时刷题什么时候用 库函数，什么时候 不用库函数

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html](https://programmercarl.com/0344.反转字符串.html)

### 类别

swap(vector.begin(), vector.end() )函数；原地操作就用双指针——左右指针；类似反转链表

### 易错点

1. 没啥，简单，原地操作想到双指针
2. 不会swap（） 没见过！
3. 空格隔开

其他:

[仅当从 VS 开发人员命令提示符处运行 VS Code 时，cl.exe 生成和调试才可用。_仅当从 vs 开发人员命令提示符处运行 vs code 时,cl.exe 生成和调试才可用。-CSDN博客](https://blog.csdn.net/lichen849/article/details/109626205)

### code

```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0,j=s.size()-1; i<=j;i++,j--){
            // i < s.size()/2我用的是i<=j也可以！！
            swap(s[i],s[j]);
        }
    }
};

int main(){
    // 输入vector
    char s;
    vector<char> words;
    while(cin>>s){
        words.push_back(s);
        if(getchar()=='\n') break;
    }

    Solution().reverseString(words);
    // 输出
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<' ';
    }
    cout<<endl;
    return 0;
}
```

## LC 541. 反转字符串II

建议：本题又进阶了，自己先去独立做一做，然后在看题解，对代码技巧会有很深的体会。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html](https://programmercarl.com/0541.反转字符串II.html)

### 类别

reverese() very easy

### 易错点

1. 不要2k，要2*k
2. string可以用 `s.begin()+i, s.end()`  还有s.size()类似vector但是不用push_back 直接+
3. #include `<algorithm>`是reverse(开始位置，结束位置)

### code

```cpp
#include<iostream>
#include<string>
#include<algorithm>
// 为了reverse
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size();i+=2*k){
            if(i+k>s.size()){
                reverse(s.begin()+i,s.end());   
            }
            else{
                reverse(s.begin()+i,s.begin()+i+k);
            }
        }
        return s;
    }
};
int main(){
    string words;
    cin>>words;
    int k;
    cin>>k;

    words=Solution().reverseStr(words,k);
    cout<<words<<endl;
  
    return 0;
}
```

## 卡码网：54.替换数字

建议：对于线性数据结构，填充或者删除，后序处理会高效的多。好好体会一下。

题目链接/文章讲解：[https://programmercarl.com/kama54.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html](https://programmercarl.com/kama54.替换数字.html)

### 类别

填充类：先扩容，再倒着填

原地操作：双指针，左右指针

### 易错点

1. **其实很多数组填充类的问题，其做法都是先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**

   这么做有两个好处：

   1. 不用申请新数组。  我不会扩容

      ```cpp
      s.resize(s.size() + count * 5)
      ```

      字符串的s.resize()
   2. 从后向前填充元素，避免了**从前向后**填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题。
   3. for中间那个终止条件，自己草稿纸上举个例子，写一下模拟每一步就能出来！！
   4. cnt初始化0 不要忘了，养成习惯，int定义就要初始化，不然会发生意外！！！！

### code

```cpp
#include<iostream>
using namespace std;
// class Solution{
// public: 
//     void 
// };

int main(){
    string s;
    cin>>s;
  
    // 先统计数字个数
    int cnt=0; //必须初始化
    for(int i=0; i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            cnt++;
        }
    }
  
    int oldsize=s.size(); //要先存一下
  
    // 扩容 why 5?因为number 6个数字 而且本来数字那一位也被换
    s.resize(s.size()+5*cnt);
    for(int j=s.size()-1,i=oldsize-1; i<j;i--,j--){
        if (s[i]>='0' && s[i]<='9'){
            s[j]='r';
            s[j-1]='e';
            s[j-2]='b';
            s[j-3]='m';
            s[j-4]='u';
            s[j-5]='n';
            j-=5; //不用j-=6 因为for最后对i,j一起--
        }
        else{
            s[j]=s[i];
        }
    }
  
    cout<<s<<endl;
    return 0;
}
```

## LC 151.翻转字符串里的单词

建议：这道题目基本把 刚刚做过的字符串操作 都覆盖了，不过就算知道解题思路，本题代码并不容易写，要多练一练。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html](https://programmercarl.com/0151.翻转字符串里的单词.html)

### 类别

原地删除空格：双指针——快慢指针(不用看文字版的版本一，不合理，直接看版本二)

整体翻，每个单词翻（遇到空格翻）

erase本来就是O(n)

### 易错点

1. 想得到吗：先整体转，再每个单词转，可以用reverse
2. 但是最他妈恶心的是：**还要删多余空格**，就是LC 27**双指针原地删除指定内容！！！！**

   1. 删的同时，还要**单词之间手动加空格**（想不出来，自己！！！！！）

      1. 先对slow(新的原地字符串)加空格（开头不可以）
      2. 再对slow加单词（从空格往后加单词，就是直到fast变成空格，说明下一个单词了！！） 一直加，所以while不是if

      for里套while，if！！！！

其他:

### code

```cpp
#include<iostream>
#include<string>
// #include<algorithm>
using namespace std;

class Solution{
public:
// 自己实现也可以！
    void reverse(string& s, int start, int end){
        // i=j要是再翻，没意义加也行！！ 左闭右闭[]
        for(int i=start,j=end; i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    void removeExtraSpaces(string& s){
        int slow=0;
        // i就是fast
        for(int i=0;i<s.size();++i){
            // if(s[i]!=' '){
            //     s[slow++]=s[i++];
            // }  //本来是这样的，遇到不是空格，就原地赋值,把fast的赋给slow
          
          
            // 妙啊！！！自己想不到，但是不能全删了，还要在单词之间通过手动加上空格
            // !!!!!!!!就是这里不会!!!!!!!!!!!!!!
            if(s[i]!=' '){
                if(s[slow]!=0) s[slow++]=' '; //开头不能加！先对slow加空格，然后对slow再加单词
                while(i<s.size() && s[i]!=' '){ //再从可空格往后加完这个单词。直到i=fast遇到下一个单词，妙自己想不到！！
                    s[slow++]=s[i++];
                }
            }
        }
    }

    string reverseWords(string s){
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(i==s.size()|| s[i]==' '){
                // 词尾翻转，或者单词结束
                reverse(s,start,i-1); //第一个从start=0开始，转第一个单词！！
                start=i+1; //i是空格
            }
        }
        return s;
    }
};
```

## 卡码网：55.右旋转字符串

建议：题解中的解法如果没接触过的话，应该会想不到

题目链接/文章讲解：

[https://programmercarl.com/kama55.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.html](https://programmercarl.com/kama55.右旋字符串.html)

### 类别

reverse（位置：位置） 不含结尾

### 易错点

1. easy的 整个转；再分别每段转！！

其他:

### code

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int k;
    cin>>k;
  
    string s;
    cin>>s;
  
    // 先整个转
    reverse(s.begin(),s.end());
    // 各自转
    reverse(s.begin(),s.begin()+k); //不含s.begin()+k
    reverse(s.begin()+k,s.end());
  
    cout<<s<<endl;//要输出，easy的
    return 0;
}
```
