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