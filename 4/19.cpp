
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