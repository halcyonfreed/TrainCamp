# 代码随想录——算法训练营DAY2
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 结构体的析构函数结尾不加分号

加，定义空构造、空析构；空构造，“合成”构造无效；空析构，“合成”析构继续起作用，譬如类有string成员，帮你析构掉

不加，就只是声明，编译器会给你“合成”构造、“合成”析构

## LC 203.移除链表元素 

建议： 本题最关键是要理解 虚拟头结点的使用技巧，这个对链表题目很重要。

题目链接/文章讲解/视频讲解：：[**https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html**](https://programmercarl.com/0203.移除链表元素.html)

### 类别

链表；增删取；虚拟头节点

### 易错点

1. 定义listnode的三种情况，析构函数的结尾{}后面不加分号
2. 删的是cur->next，借助cur
3. 打印Listnode的初始：究竟是head还是head->next；结束条件判的是cur还是cur->next非空！‘
4. 要不要设置Pre，cur混乱
5. 打印的getchar()=='\n'放在哪里！！

其他:

### code

```cpp
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    // 三种情况都要写
    ListNode(int val): val(val),next(nullptr){} //不用分号，不然是空析构,;空的
    ListNode():val(0),next(nullptr){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};
```

solution

```cpp

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        // cur指的是被删的前一个，帮助删当前那个！
        ListNode* cur=dummyhead;
        
        while(cur->next){//条件写错！！
            if(cur->next->val==val){
                ListNode* tmp=cur->next;
                cur->next=cur->next->next; //cur的next成员内容是cur的next指的那个指针的成员next
                delete tmp;
            }
            else cur=cur->next;
        }
        return dummyhead->next;        
    }
};

```

```cpp
// 4大步，读入，打印；运算以后，打印新的；
int main(){
    //------ 输入
    int num;
    // 新链表
    ListNode* dummyhead=new ListNode();//这个第一个不要，不是真的头，里面的值不是我输入的
    ListNode* pre=dummyhead;
    ListNode* cur=pre->next; //默认是nullptr

    while(cin>>num){
        // if(getchar()=='\n') break;
        cur=new ListNode(num); // 创建新的链表，就是新的一小段尾巴接上去
        pre->next=cur;
        pre=cur;
        
        if(getchar()=='\n') break;
        //不能放在最前面，不然最后一个数字读不进来！！！
    }

    //------ 输出
    cur=dummyhead->next; //dummyhead的值不是我输入的，是默认的0，所以->next
    // while(cur->next){
    while(cur){
        // cur->next是空指针，到尾巴了，但是这个是最后，要处理，所以是cur不是cur->next
        cout<<cur->val<<' ';
        cur=cur->next;
    }
    cout<<endl;

    int val;
    cin>>val;

    ListNode* newhead=Solution().removeElements(dummyhead->next,val);

    //--------输出新的
    cur=newhead;
    while(cur){
        cout<<cur->val<<' ';
        cur=cur->next;
    }
    cout<<endl;
    return 0;    
}

```



## LC 707.设计链表

[题目链接/文章讲解/视频讲解：[https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html](https://programmercarl.com/0707.设计链表.html)](https://programmercarl.com/0707.设计链表.html)

### 类别

链表；增删取；虚拟头节点

### 易错点

1. 

其他:

### code

## LC 707.设计链表

[题目链接/文章讲解/视频讲解：[https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html](https://programmercarl.com/0707.设计链表.html)](https://programmercarl.com/0707.设计链表.html)

### 类别

链表；增删取；虚拟头节点

### 易错点

1. 

其他:

### code
