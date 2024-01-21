# 代码随想录——算法训练营DAY11


## ACM模式输入输出参考

[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## LC 20. 有效的括号 

讲完了栈实现队列，队列实现栈，接下来就是栈的经典应用了。 

大家先自己思考一下 有哪些不匹配的场景，在看视频 我讲的都有哪些场景，落实到代码其实就容易很多了。 

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html](https://programmercarl.com/0020.有效的括号.html) 

 

### 类别

匹配问题：用栈data structure

### 易错点

1. 自己想的全3种不匹配情况，典型用栈
2. 一开始的特殊情况，奇数一定不匹配！
3. 技巧，遇到左括号压入右括号
4. stack没有.back()

自己两个问题！！！

​      else if(st.top()!=s  || st.empty()) return false;  //这样会非法 因为st可能本身是empty，顺序很重要！！！

​      else st.pop(); //这行漏了

其他:

### code

不难

```cpp
#include<string>
#include<stack>
class Solution {
public:
    bool isValid(string S) {
        if(S.size()%2!=0) return false;
        stack<char> st;
        // string的遍历 我不会用，for
        for(char s :S)
        {

            // 处理左括号
            if (s=='{')  st.push('}'); //技巧，不直接压左括号
            else if (s=='(')  st.push(')');
            else if (s=='[')  st.push(']');


            // ------处理右括号
            //数量一样但是对不上；右括号多
            else if(st.top()!=s  || st.empty()) return false;
            else st.pop(); //这行漏了
        }
        // 还剩下左括号多了，false
        return !st.empty();
    }
};
```



## LC 1047. 删除字符串中的所有相邻重复项 

栈的经典应用。 

要知道**栈**为什么适合做这种**类似于爱消除的操作**，因为栈帮助我们**记录了 遍历数组当前元素时候，前一个元素是什么**。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html](https://programmercarl.com/1047.删除字符串中的所有相邻重复项.html)

### 类别

**stack.pop() .push() .top() .empty()**

**string.pop_back() .push_back() .back() .empty()  .front() .push_front()**

**vector.push_back()**

### 易错点

1. 如果用栈，结果要再倒一下！！

   reverse(string.begin(),string.end())

   ```cpp
   return reverse(result.begin(),result.end()); //这种写法错 reverse() 函数返回的是一个空值（void），因此不能用作返回值
   ```

2. C++： 又忘了.sort() .find() .reverse()需要include<algorithm

3. string.back()  .empty() .front()  .push_back()  .pop_back()

4. 🤣🤣🤣🤣🤣🤣我滴个妈 排查错误 打印了好久，以后可以打断点然后在调试台打印，这样就不用改动代码了！！！看出来那里错了吗   num1和num2计算顺序错了，对＋和*影响不大，对-和/就要命了！！

   ```
   if(tokens[i] == "+" ) st.push(num1+num2); 
   if(tokens[i] == "-" ) st.push(num1-num2); 
   if(tokens[i] == "*" ) st.push(num1*num2); 
   if(tokens[i] == "/" ) {st.push(num1/num2); cout<<num1/num2<<' ';} 
   ```

   

其他:

### code

```cpp
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        // 法一专门弄个stack，再result转成string
        stack<char> st;
        for(char s:S){
            if(st.empty() || st.top()!=s) st.push(s); // ||前后两个条件不可以调换
            else st.pop();
        }
        // 转成string不会
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop(); //要pop！！
        }
        // return reverse(result.begin(),result.end()); //这种写法错 reverse() 函数返回的是一个空值（void），因此不能用作返回值
        reverse(result.begin(),result.end());
        return result;


        // 法二 不用stack，直接string
        string result;
        for(char s:S){        
            if(result.empty() || result.back()!=s) result.push_back(s);
            else result.pop_back();
        }       
        return result;
    }
};
```



## LC 150. 逆波兰表达式求值 

本题不难，但第一次做的话，会很难想到，所以先看视频，了解思路再去做题

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html](https://programmercarl.com/0150.逆波兰表达式求值.html)



### 类别

后缀表达式就是后序遍历二叉树

### 易错点

1. 自己想没思路，遇到数字push；遇到运算符（根节点）pop 2个数字（叶子），并把结果push回去！！ ！！！自己想不到的后序遍历
2. 力扣修改了后台测试数据，需要用longlong 数据类型！！**32 位** 整数
3. `stoll` 函数将字符串转换为 `long long` 类型的整数！！

其他:

### code

尼玛按我的就是过不了

报错：为什么

```
Line 172: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0b6 for type 'long long', which requires 8 byte alignment (stl_deque.h)
0xbebebebebebec0b6: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/stl_deque.h:181:16
```

```cpp
#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; //中间结果
        for (int i=0; i<tokens.size();i++){
            cout<<tokens[i]<<' ';
            if (tokens[i]>="0" && tokens[i]<="9") st.push(stoll(tokens[i]));
            // else if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            else{
                long long num1=st.top(); //先取再pop
                st.pop();

                long long num2=st.top(); 
                st.pop();

                if(tokens[i] == "+" ) st.push(num2+num1); 
                if(tokens[i] == "-" ) st.push(num2-num1); 
                if(tokens[i] == "*" ) st.push(num2*num1); 
                if(tokens[i] == "/" ) st.push(num2/num1);


                // 下面是要命的错误，num2和num1的顺序反了！！
                // cout<< num1 <<' '<< num2<< " ";
                // if(tokens[i] == "+" ) st.push(num1+num2); 
                // if(tokens[i] == "-" ) st.push(num1-num2); 
                // if(tokens[i] == "*" ) st.push(num1*num2); 
                // // if(tokens[i] == "/" ) {st.push(num1/num2); cout<<num1/num2<<' ';}              
            }
            cout<<st.top()<<endl;

        }
        // return st.top();
        int result=st.top();
        return result;
    }
};

int main(){
    string s;
    vector<string> words;
    while(cin>>s){
        words.push_back(s);
        if (getchar()=='\n') break;
    }
    cout<<Solution().evalRPN(words)<<endl;
    return 0;
}
```

