#include<iostream>
using namespace std;
<<<<<<< HEAD
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){};
    ListNode(int x) : val(x),next(nullptr){}; // 构造函数结尾没有; why why????，冒号 : 是成员初始化列表（Member Initialization List）的开始标志。
    ListNode(int x, ListNode* next): val(x), next(next){}
=======

struct ListNode{
    int val;
    ListNode* next;
    // 三种情况都要写
    ListNode(int val): val(val),next(nullptr){} //不用分号，不然是空析构,;空的
    ListNode():val(0),next(nullptr){}
    ListNode(int val, ListNode* next):val(val),next(next){}
>>>>>>> 5cf4dbce07096926fd25f889f5e49c82ecf01dce
};
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
<<<<<<< HEAD
        ListNode* dummyHead=new ListNode();
        dummyHead->next=head;

        ListNode* cur=dummyHead;
        while(cur->next){00
            if(cur->next->val==val){
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete cur->next;
            }
            else cur=cur->next;
        }
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};
int main(){
    int num,val;

    ListNode* head=new ListNode(); //默认val 0
    ListNode* cur=nullptr;
    ListNode* pre
    while(cin>>num){
        if(getchar()=='\n') break; //放最后，不能放最前，不然缓冲区最后一个读了就跳了，读不到链表里！
        cur=new ListNode(num);
        pre->next=cur;


    }
}
=======
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

    // 打印
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
