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

