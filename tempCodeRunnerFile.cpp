<<<<<<< HEAD
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         // ListNode* dummyHead= new ListNode(0);
//         ListNode* dummyHead= new ListNode();
//         dummyHead->next=head;

//         ListNode* cur=dummyHead;
//         while(cur->next){
//         // while(cur->next!=NULL){
//             if(cur->next->val==val){//不是cur->val==val，比的是cur->next，删的是cur->next，借助cur
//                 // 下面两行错误写法，直接把新的cur->next删没了nonono
//                 // cur->next=cur->next->next;
//                 // delete cur->next;

//                 ListNode* tmp=cur->next;
//                 cur->next=cur->next->next;
//                 delete tmp; //释放内存！   
//             }
//             else{
//                 cur=cur->next; //正常往后
//             }
//         }
//         head=dummyHead->next;
//         delete dummyHead; //释放内存
//         return head;
//     }
// };


#include <iostream>
using namespace std;

// 链表定义，并给出两个有参构造函数
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* _next):val(_val),next(_next){}
};

int main()
{

	// 根据控制台的输入，创建一条单链表
    ListNode* LHead = new ListNode(-1); //是头节点，一会儿删了dummy head; val=-1, next=nullptr
    // 用新链表赋值pre,cur
    ListNode* pre = LHead; // pre指向Lhead头
    ListNode* cur = pre->next; //cur

    int num;
    while(cin >> num)
    {
        if(getchar()=='\n') break;
        // cur = new ListNode(num); // cur读进来新的，val=num, next=nullptr就是新的真正的尾巴！
        // pre->next = cur; // pre->next指到新的cur
        // pre = cur; //pre往后移动到新的cur，往后移


    }
    
    cur = LHead->next;
    
    // 输出单链表的value
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    
    cout << endl;
    
    return 0;
}
=======
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

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {

        if(index > _size) return;
        if(index < 0) index = 0;        
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
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

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};

int main(){
    // 输入
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

    // 输出
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

    cur=newhead;
    while(cur){
        cout<<cur->val<<' ';
        cur=cur->next;
    }
    cout<<endl;
    return 0;    
}

/* 这个初始化特别烦，究竟是head还是head->next
要不要设置Pre，cur混乱
*/
>>>>>>> 5cf4dbce07096926fd25f889f5e49c82ecf01dce
