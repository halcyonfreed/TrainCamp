struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val),next(nullptr){} //不用分号，不然是空析构,;空的
    ListNode():val(0),next(nullptr){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        // cur指的是被删的前一个，帮助删当前那个！
        ListNode* cur=dummyhead;
        
        while(cur->next->next){
            if(cur->next->val==val){
                ListNode* tmp=cur->next;
                cur->next=cur->next->next; //cur的next成员内容是cur的next指的那个指针的成员next
                delete tmp;
            }
            else cur=cur->next;
        }        
    }
};
