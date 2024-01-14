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