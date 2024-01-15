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
