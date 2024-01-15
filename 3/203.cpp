#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){};
    ListNode(int x) : val(x),next(nullptr){}; // 构造函数结尾没有; why why????，冒号 : 是成员初始化列表（Member Initialization List）的开始标志。
    ListNode(int x, ListNode* next): val(x), next(next){}
};
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
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