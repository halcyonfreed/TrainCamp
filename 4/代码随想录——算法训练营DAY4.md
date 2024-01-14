# 代码随想录——算法训练营DAY4
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)



所有的只看题目，自己想一下；在草稿纸上画一下过程！！

## 核心

1. 每次操作单位涉及几个指针：cur, cur->next, cur->next->next
2. 链表的核心：断开谁，又指向谁
3. 断开，指向顺序，要不要临时存过程变量！！

## LC 24 两两交换链表中的节点

本题链表操作就比较复杂了，建议大家先看视频，视频里我讲解了注意事项，为什么需要temp保存临时节点。

题目链接/文章讲解/视频讲解： [https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html](https://programmercarl.com/0024.两两交换链表中的节点.html)

### 类别

链表；算难的！！

### 易错点

1. 在草稿纸上画一画，每次操作单位涉及几个指针：cur, cur->next, cur->next->next
1. 是谁就用=别用→会搞混next和=（不一样），断开画×，再指向新的→，→上标序号
1. 写出伪代码，并画出新的链表连接；写一步画一步，就明白了对不对了，不会下不去手了
1. while内 条件可以先不写，后面根据操作对象合法吗来填空，养成习惯

其他:

### code

```cpp
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){} //无; 否则;代表是空语句，空析构空构造
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x),next(next){}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        // 操作cur, cur.next,设dummyhead换头节点
        ListNode* dummyhead=new ListNode();
        dummyhead->next=head;

        ListNode* cur=dummyhead;
        while(cur->next && cur->next->next){
            // 条件可以先不写，后面根据操作对象合法吗来填空，养成习惯; 先cur->next
            // 是根据后面才补要存什么临时变量，不是一开始就想出来的
            ListNode* tmp=cur->next;
            ListNode* tmp1=cur->next->next->next;

            cur->next=cur->next->next;
            cur->next->next=tmp; //cur->next指向原来cur的next
            tmp->next=tmp1;

            cur=cur->next->next; //这行漏了，不是cur->next->next->next
        }
        return dummyhead->next;
    } 
};

int main(){
    int num;
    ListNode* dummyhead=new ListNode();
    ListNode* pre=dummyhead;
    ListNode* cur=pre->next;

    while(cin>>num){
        cur=new ListNode(num);
        pre->next=cur;
        pre=cur;
        if (getchar()=='\n') break;
    }
    
    ListNode* newhead=Solution().swapPairs(dummyhead->next);

    // ListNode* cur=newhead; //cur已定义过了
    cur=newhead;
    while(cur){
        cout<<cur->val<<' ';
        cur=cur->next; //忘记
    }
    cout<<endl;
    return 0;

}
```



## LC 19.删除链表的倒数第N个节点

双指针的操作，要注意，删除第N个节点，那么我们当前遍历的指针一定要指向 第N个节点的前一个节点，建议先看视频。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html](https://programmercarl.com/0019.删除链表的倒数第N个节点.html)

### 类别



### 易错点

1. 

其他:

### code

## 面试题 02.07. 链表相交

没有视频讲解，大家注意 数值相同，不代表指针相同。

题目链接/文章讲解：[https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html](https://programmercarl.com/面试题02.07.链表相交.html)

### 类别



### 易错点

1. 

其他:

### code

## LC 142.环形链表II 

算是链表比较有难度的题目，需要多花点时间理解 确定环和找环入口，建议先看视频。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html](https://programmercarl.com/0142.环形链表II.html)

### 类别

数学公式规律推导，面试当场做不出啊！，可能推不出，但大胆猜测吧；

### 易错点

1. 

其他:

### code
