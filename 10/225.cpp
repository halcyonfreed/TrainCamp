#include<queue>
#include<iostream>
using namespace std;

class MyStack{
public:
    queue<int> que;
    MyStack(){}  // 析构，初始化
    void push(int x) {
        que.push(x);
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }

    // 优化版，只用一个queue
    int pop(){
        int size = que.size();
        size--;  //只留尾部最后一个，弹出前size-1个
        while(size--){
            que.push(que.front()); //倒顺序
            que.pop(); //不要忘了pop！！！
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;

    }
};