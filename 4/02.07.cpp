#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x,ListNode* next): val(x),next(next){}
};

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        ListNode* curA=headA;
        ListNode* curB=headB;

        //不是值相等，是指针指的内存地址相同！
        // 先求出lenA, lenB但是为什么？？根本想不到方法
        int lenA=0,lenB=0;
        while(curA!=nullptr){
            lenA++;
            curA=curA->next;
        }
        while(curB!=nullptr){
            lenB++;
            curB=curB->next;
        }

        // 再指回头
        curA=headA;
        curB=headB;
        // A比B长
        if(lenB>lenA){
            swap(lenA,lenB); // swap内置函数
            swap(curA,curB);
        }

        // 为什么尾部要对齐！因为看题，因为交点以后，长度一样，尾部都是一样的对齐的！！
        int gap=lenA-lenB;
        while(gap--){
            curA=curA->next;
        }        
        while(curA){
            if(curA==curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return nullptr;
    }
};