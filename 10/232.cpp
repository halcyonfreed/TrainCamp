#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> stIn; //这个我会
    stack<int> stOut;

    MyQueue(){

    } //这里就是构造函数类似，和class名相同，所以不要分号！！！！，不然是空构造或者空析构
    void push(int x){
        stIn.push(x);
    }

    int pop(){
        // 分情况讨论
        // stOut空的，需要先stIn换顺序，全部压进来
        if(stOut.empty()){
            // 要全部弹出啊
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();// 压完以后，不要忘了stIn弹出啊啊啊啊啊
            }
        }
        // 如果不是空的就直接弹出，但是如果是空的，stIn加到stOut以后一样操作，所以不用else！！！
        int result=stOut.top(); 
        stOut.pop(); //要先取top再pop，不能pop啊
        return result;
    }
    int peek(){
        // 复用类内成员函数
        int res=this->pop(); //关键字"this"指的是当前对象的指针，引用当前对象,用于访问当前对象的成员函数和成员变量。
        stOut.push(res);
        return res;
    }

    bool empty(){
        return stIn.empty() && stOut.empty();
    }
};
int main(){
    // MyQueue myQueue = new MyQueue();  //问gpt这个错误是因为你在创建MyQueue对象时使用了new关键字，但是在C++中，当你使用new来创建对象时，返回的是指向对象的指针。所以，你需要将对象的类型从MyQueue*更改为MyQueue，并且不要使用new关键字。
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout<<myQueue.peek()<<endl; // return 1
    myQueue.pop(); // return 1, queue is [2]
    cout<<myQueue.empty()<<endl; // return false
    return 0;
}
