# 代码随想录——算法训练营DAY10
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)
## 栈队列基础

1. def：

   1. stack：只开一个口，FILO
   2. queue：两边开口，FIFO

2. 深入扫盲

   1. C++中stack 是容器么？

      不是container，Stack queue都是stl （standard template library）中的adaptive container

   2. 我们使用的stack是属于哪个版本的STL？

      三个版本：HP STL（鼻祖）；P.J.Plauge STL（VS用的不开源）；**SGI STL** （默认这个，开源，linux编译器GCC 用的）

   3. 我们使用的STL中stack是如何实现的？

      1. **栈是以底层容器完成其所有的工作，但本身不是容器，对外提供统一的接口，底层容器是可插拔的（也就是说我们可以控制使用哪种容器来实现栈的功能）。** 可以是vector，deque（默认是用双向队列deque! 只要封住一段，只开通另一端就可以实现栈），list 
   2. 所以STL中栈往往不被归类为容器，而被归类为container adapter（容器适配器）。
      3. SGI STL的队列和栈的底层实现一样，也是deque

   4. stack 提供迭代器来遍历stack空间么？

      没有，不提供iterator无法遍历！！！！ 比如set，map，vector都有专门的iterator可以遍历

## LC 232.用栈实现队列  

大家可以先看视频，了解一下模拟的过程，然后写代码会轻松很多。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html](https://programmercarl.com/0232.用栈实现队列.html) 

### 类别



### 易错点

1. 因为queue（FIFO）=两个stack，提示你了用两个stack（FILO），一个stackin负责push 输入 判断empty，一个stackout负责输出、取top（把顺序颠倒）
2. POP: **pop的时候，操作就复杂一些，输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入,这里想清楚，一次性倒着压进去）**，再从出栈弹出数据，如果输出栈不为空，则直接从出栈弹出数据就可以了。  **先取top，再pop** 特别！！！
3. empty判断：不会，两个都空！想不到

其他

### C++

1. this关键字：
   1. 用处： 复用类内成员函数pop
   2. 关键字"this"指的是当前对class 定义了一个实例对象object的指针，引用当前对象,用于访问当前对象的成员函数和成员变量。

2. #include<stack>	stack基本操作：.push(), .pop(), .size(), .empty()  .top() 不太清楚，要记牢！！

3. new关键字报错，直接问gpt它会帮你修改，好强啊！！！

### code

```cpp
#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> stIn; //这个我会
    stack<int> stOut;

    MyQueue(){

    } //这里就是构造函数类似，和class名相同，所以不要分号！！！！，不然是空构造或者空析构
    void push(int x){
        stIn.push(x);
    }

    int pop(){
        // 分情况讨论
        // stOut空的，需要先stIn换顺序，全部压进来
        if(stOut.empty()){
            // 要全部弹出啊
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();// 压完以后，不要忘了stIn弹出啊啊啊啊啊
            }
        }
        // 如果不是空的就直接弹出，但是如果是空的，stIn加到stOut以后一样操作，所以不用else！！！
        int result=stOut.top(); 
        stOut.pop(); //要先取top再pop，不能pop啊
        return result;
    }
    int peek(){
        // 复用类内成员函数
        int res=this->pop(); //关键字"this"指的是当前对象的指针，引用当前对象,用于访问当前对象的成员函数和成员变量。
        stOut.push(res);
        return res;
    }

    bool empty(){
        return stIn.empty() && stOut.empty();
    }
};
int main(){
    // MyQueue myQueue = new MyQueue();  //问gpt这个错误是因为你在创建MyQueue对象时使用了new关键字，但是在C++中，当你使用new来创建对象时，返回的是指向对象的指针。所以，你需要将对象的类型从MyQueue*更改为MyQueue，并且不要使用new关键字。
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout<<myQueue.peek()<<endl; // return 1
    myQueue.pop(); // return 1, queue is [2]
    cout<<myQueue.empty()<<endl; // return false
    return 0;
}

```



## LC 225. 用队列实现栈 

大家惯性思维（不是，是因为题目描述要求用两个），以为还要两个队列来模拟栈，其实只用一个队列就可以模拟栈了。

建议大家掌握一个队列的方法（真的吗，确实直接原地改顺序，把尾 出口的元素放回头 入口！！！)，更简单一些，可以先看视频讲解

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html](https://programmercarl.com/0225.用队列实现栈.html) 

用队列实现栈还是有点别扭，强调是单向队列，**很多算法题目主要是对知识点的考察和教学意义远大于其工程实践的意义，所以面试题也是这样**

### 类别



### 易错点

本质上就是stack和que的弹出顺序不一样！！

依然想着用一个输入队列，一个输出队列，**队列模拟栈，其实一个队列就够了（不够准确）**两个队列来模拟栈，只不过没有输入和输出的关系，而是另一个队列完全用来备份的（用来换顺序的，其实还是用来输出的但是不一样）

因为que两头开，stack 一头开，弱一点！！

1. 上一题是：放到stIn里，从stOut里取
2. 这题：都在que1里取和放，但是取的时候，先把前面的都扔到que2，取que1最后一个顺序倒过来的！！！我的妈呀（直接看优化版，优化版就是不要que2，而实直接原地把que1顺序改了，把尾 出口的元素放回头 入口）

其他:



今天虽然在宿舍玩了很久，但是还是狠下心，必须要完成今天的打卡，听到了图书馆闭馆音乐 《城南花已开》好听，而且也完成了今天的打卡，我好棒！！

### C++

1. #include<queue> 基本操作：queue.push(); .pop() .size()  .front()类似stack.top()  .empty()   但是多了一个.back()因为stack底尾部是封住的所以没有back()

### code

```cpp
#include<queue>
#include<iostream>
using namespace std;

class MyStack{
public:
    queue<int> que;
    MyStack(){}  // 析构，初始化
    void push(int x) {
        que.push(x);
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }

    // 优化版，只用一个queue
    int pop(){
        int size = que.size();
        size--;  //只留尾部最后一个，弹出前size-1个
        while(size--){
            que.push(que.front()); //倒顺序
            que.pop(); //不要忘了pop！！！
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;

    }
};
```

