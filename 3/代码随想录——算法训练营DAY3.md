# 代码随想录——算法训练营DAY3

## ACM模式输入输出参考

[acm模式输入输出](https://blog.csdn.net/qq_46046431/article/details/129266738?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170488815716800197032506%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=170488815716800197032506&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129266738-null-null.142%5Ev99%5Epc_search_result_base6&utm_term=acm%E6%A8%A1%E5%BC%8F%E8%AF%BB%E5%85%A5vector&spm=1018.2226.3001.4187)

## 结构体的析构函数结尾不加分号

加，定义空构造、空析构；空构造，“合成”构造无效；空析构，“合成”析构继续起作用，譬如类有string成员，帮你析构掉

不加，就只是声明，编译器会给你“合成”构造、“合成”析构

## LC 203.移除链表元素

建议： 本题最关键是要理解 虚拟头结点的使用技巧，这个对链表题目很重要。

题目链接/文章讲解/视频讲解：：[**https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html**](https://programmercarl.com/0203.移除链表元素.html)

### 类别

链表；设虚拟头节点，不是真的头

### 易错点

1. 定义listnode的三种情况，析构函数的结尾{}后面不加分号
2. 删的是cur->next，借助cur
3. 打印Listnode的初始：究竟是head还是head->next；结束条件判的是cur还是cur->next非空！‘
4. 要不要设置Pre，cur混乱
5. 打印的getchar()=='\n'放在哪里！！

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

1. 链表不知道长度的，所以不用for找位置，用while ，cur然后cur->next非空来找位置
2. ```cpp
   delete tmp;
   //delete命令指示释放了tmp指针原本所指的那部分内存，
   //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
   //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
   //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
   tmp=nullptr;
   ```

   先找位置，停在index前一个, 因为借助前一个删掉index这个；

   但是因为cur初始是dummyhead，而且index不是下标，就是实际第index个，从1开始

   所以还是while（n--）反正就是带个数进去看看

其他:

### code

```cpp


class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    int get(int index){
        if(index>(_size-1) || index<0) return -1;

        // 先找到位置，链表不用for找位置，用cur然后cur->next非空来找位置
        LinkedNode* cur=_dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val){
        // 不用找
        LinkedNode* newhead=new LinkedNode(val);
        newhead->next=_dummyHead->next; //这里错了漏->next
        _dummyHead->next=newhead; //新投
        _size++;
    }

    void addAtTail(int val){
        LinkedNode* newnode=new LinkedNode(val);

        // 找到尾巴先！
        LinkedNode* cur=_dummyHead;
        while(cur->next){
            // 养成习惯，最后写while里条件，最后一个停下所以cur->next
            cur=cur->next;
        }
        cur->next=newnode;
        _size++;
    }

    void addAtIndex(int index, int val){
        // 情况太多了！！
        if (index>_size) return; //不加
        if(index<0) index=0;

        LinkedNode* newNode=new LinkedNode(val);
        // 找到位置先！
        LinkedNode* cur=_dummyHead;
        while(index--){
            cur=cur->next;
        }
        // 注意顺序，自己画个图就懂了！！！
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
      
    void deleteAtIndex(int index){
        if (index >= _size || index < 0) {
            return;
        }

        // 先找位置，停在index前一个，因为借助前一个删掉index这个；但是因为cur初始是dummyHead，而且index不是下标，就是实际第index个，从1开始
        LinkedNode* cur=_dummyHead;
        while(index--) {
                cur = cur ->next;
            }
            LinkedNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            //delete命令指示释放了tmp指针原本所指的那部分内存，
            //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
            //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
            //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
            tmp=nullptr;
            _size--;
        }
// 超时妈的
    void printLinkedList() {
        // 和答案不一样
        LinkedNode* cur = _dummyHead->next;
        while (cur){
            cout<<cur->val<<' ';
            cur=cur->next;
        }
        cout<<endl;
    }
private:
// 一定要写啊啊啊啊，不然会报错内部变量，扔到private里保护a起来！
    int _size;
    LinkedNode* _dummyHead;
};

```

## LC 206.反转链表

建议先看我的视频讲解，视频讲解中对 反转链表需要注意的点讲的很清晰了，看完之后大家的疑惑基本都解决了。

题目链接/文章讲解/视频讲解：[https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html](https://programmercarl.com/0206.翻转链表.html)

### 类别

链表；改next方向；递归法没看！

### 易错点

1. 不用定义新的链表，直接原地改next方向就行！特别妙
2. 初始化cur=head, pre=nullptr 想不到
3. 先存temp=cur->next 再移pre, cur
4. while条件cur还是cur->next 看注释！

其他: 可以在vscode里打断点调试

### code

```cpp
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next=nullptr;
    ListNode():val(0),next(nullptr){} //没有分号，析构函数，不然;代表是一个空析构
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x),next(next){}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 默认没val,也没有next,只是开辟一段地址
        // cout<<temp<<endl;
        // ListNode* pre; // 这样不行
        ListNode* pre=NULL; //没有val,也没有next,但是=NULL的效果
        // cout<<pre<<endl;
        ListNode* cur=head;

        while(cur){
            // cur->next=null是尾巴，但是cur要处理，是cur==nullptr停
            temp=cur->next; //先存下来
            cur->next=pre; //再断，换方向
            pre=cur; //后移
            cur=temp;
        }
        return pre;
    }
};

// 递归法
class Solution2{
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        //递归三部曲： 返回和参数类型； 结束条件；单层逻辑
        if(cur == NULL) return pre; //空链表不用反转了

        ListNode* temp = cur->next; //存下一个
        cur->next = pre; // 指回前一个,换方向，两两处理！！！
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);  //套娃
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }
};

int main(){
    int num;
    ListNode* dummyhead=new ListNode(); //默认val=0,next=nullptr
    // cout<<dummyhead<<endl; //0x10
    ListNode* pre=dummyhead;
    ListNode* cur=pre->next;

    while(cin>>num){
        cur=new ListNode(num);
        pre->next=cur; //连上新的
        pre=cur; //移pre

        if(getchar()=='\n') break;//放最后！
    }

    ListNode* head=Solution().reverseList(dummyhead->next); //传入的不是dummyhead!!!那个val不是我输入的，所以扔掉！！

    // 输出
    cur=head;
    while (cur){
        // 最后一个要处理，所以cur，不是cur->next
        cout<<cur->val<<' ';
        cur=cur->next;
    }
    cout<<endl;
    return 0;
}
```
