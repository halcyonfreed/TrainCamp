# 代码随想录——算法训练营DAY4
## ACM模式输入输出参考
[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)



所有的只看题目，自己想一下；在草稿纸上画一下过程！！

## 核心

1. 每次操作单位涉及几个指针：cur, cur->next, cur->next->next
2. 链表的核心：断开谁，又指向谁
3. 断开，指向顺序，要不要临时存过程变量！！

## 链表特性

长度不可以直接获取，类似数组vector ，vector.size()；所以需要fast指针遍历到尾巴，来变相走vector.size()步；

所以链表题一般用while少用for!!!!

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

快慢指针（太秒了，想不到啊，用让fast先走n+1，总感觉一个指针就行了，但是因为长度不知道，所以先用fast遍历出长度，slow实际操作删除！）

### 易错点

1. 想不到为什么要用双指针——**快慢指针，原地操作**

2. 如果删掉倒数第N节点是头，所以凡是**涉及删头节点，就设置dummyhead虚拟头**

3. **有个问题，既然知道走几步！为什么不用for，因为链表没有size直接获取长度，很少用for，链表类型题一般用while，以->next==NULL判断到尾巴了！！**

4. ！！！！！！！fast先走n+1，那么剩下走size-(n+1)，slow也走这么多停，说明停在了倒数n+1的位置，就是倒数n的前一个，删去倒数n！！1

   
   
   其他：**养成习惯，先写while里内容，再根据变量合法吗，填入条件**； while（n--)

### code

```cpp

//核心代码
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 先设dummyhead，以防被删的是head
        ListNode* dummyhead=new ListNode();
        dummyhead->next=head;

        // 初始化
        ListNode* fast=dummyhead; //用来遍历出长度，这个是链表特有的，长度没法像数组vector直接获取！！！
        ListNode* slow=dummyhead;

        // fast先走n+1步，不可以--n，是先取n，再n-1的
        while(n-- && fast){
            // 养成习惯，先写while里内容，再根据变量合法吗，填入条件
            fast=fast->next; //是fast不是判断fast->next先判断有没有！！
        }
        fast=fast->next; //再走一步！

        // // slow找位置，while条件先空着
        // while(fast->next){
        //     fast=fast->next; //fast->next是空，fast到尾巴了，但是还要走一步,但此时fast->next已经不合法了，所以最后一步放外面
        //     slow=slow->next;
        // }
        // slow=slow->next; //走到被删的前一个


        // 上面这样不行！！
        while(fast){
            fast=fast->next; //fast走到尾巴，非空，然后fast移到null停下
            slow=slow->next; //slow移到被删前，对的
        }

        ListNode* tmp= slow->next;
        slow->next=slow->next->next;
        delete tmp; //tmp可以后面加，释放内存
        return dummyhead->next;
    }
};
```



## 面试题 02.07. 链表相交

没有视频讲解，大家注意 数值相同，不代表指针相同。

题目链接/文章讲解：[https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html](https://programmercarl.com/面试题02.07.链表相交.html)

### 类别

### 易错点

妈的，题都 没看懂，这两题，和下面那题都是题都没看懂！！！！！尼玛，给我skip A, skipＢ干嘛的！

其他:

太妙了！！！观察题目啊，发现从交点以后的长度一样，所以结尾都一样！！！！ 所以先移成尾部对齐！！！！！

### code

```cpp
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x,ListNode* next): val(x),next(next){}
};

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        ListNode* curA=headA;
        ListNode* curB=headB;

        //不是值相等，是指针指的内存地址相同！
        // 先求出lenA, lenB但是为什么？？根本想不到方法
        int lenA=0,lenB=0;
        while(curA!=nullptr){
            lenA++;
            curA=curA->next;
        }
        while(curB!=nullptr){
            lenB++;
            curB=curB->next;
        }

        // 再指回头
        curA=headA;
        curB=headB;
        // A比B长
        if(lenB>lenA){
            swap(lenA,lenB); // swap内置函数
            swap(curA,curB);
        }

        // 为什么尾部要对齐！因为看题，因为交点以后，长度一样，尾部都是一样的对齐的！！
        int gap=lenA-lenB;
        while(gap--){
            curA=curA->next;
        }        
        while(curA){
            if(curA==curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return nullptr;
    }
};
```



## LC 142.环形链表II   这道题放弃了！！

算是链表比较有难度的题目，需要多花点时间理解 确定环和找环入口，建议先看视频。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html](https://programmercarl.com/0142.环形链表II.html)

### 类别

数学公式规律推导，面试当场做不出啊！，可能推不出，但大胆猜测吧；

### 易错点

这道题目，不仅考察对链表的操作，而且还需要一些数学运算。

主要考察两知识点：

- 判断链表是否环:**相对于slow来说，fast是一个节点的速度Δv=1节点！靠近slow的**，所以fast一定可以和slow重合, 太妙了

- 如果有环，如何找到这个环的入口： **fast slow相遇的地方不是环的入口！！！！！** 

  n=1时，x=z， 所以slow=fast相遇以后　dslow=x+y dfast=x+y+z 推出了x=z

  此时相遇到环的入口处是z=x， 入口处到环的入口处是x，所以一个从相遇点每次走一个，一个从头每次走一个，再次遇见就是入口处x！

  不行这个问题太多看不懂，

  while里的条件写不对！！

### code

```cpp
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;

        // while(fast && fast->next->next){
        while(fast && fast->next){
            // 最后写while的结束条件
            slow=slow->next;
            fast=fast->next->next;

        // 找到以后，一个在头再走x，一个在相遇处再走y，再次遇见就是入口处
            if (slow==fast){
                ListNode* index1=fast;
                ListNode* index2=head;
                
                while(index1!=index2){
                    // 最后写结束条件
                    index1=index1->next; //从fast再走z步，从head再走x步，走到环的入口处！！
                    index2=index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};
#include<iostream>
using namespace std;

int main(){
    int num;
    ListNode* dummyhead=new ListNode(0);
    ListNode* pre=dummyhead;
    ListNode* cur=pre->next;

    while(cin>>num){
        pre->next=new ListNode(num);
        cur=cur->next;
        if(getchar()=='\n') break;
    };

    cur=Solution().detectCycle(dummyhead->next);
    // while(cur){
    //     cout<<cur->val<<' ';
    //     cur=cur->next;
    // }
    cout<<cur->val<<endl;
    return 0;
}


```

