#include<deque>
class Solution {
private:
    class MyQueue{
    public:
        // 我不理解啊，class是private，但是里面的成员方法是public,说明只在class内有效！！
        // 单调队列，只维护最大的，而且最大的在出口弹出，所以单调
        deque<int> que;
        void pop(int value){
            if(!que.empty() && value==que.front()){
                que.pop_front();
            }
        }
    }
};