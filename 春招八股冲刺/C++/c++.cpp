/*
1 ptr和ref区别
*/
#include<iostream>
using namespace std;
void add(int* p, int& r, int num){
    *p +=num;
    r+=num;
}

void addPtr(int* p,int num){
    *p+=num;
}

void addRef(int& r,int num){
    r+=num;
}

int main(){
    int x=10;
    int* p=&x; //初始化*p存x的地址
    int& r=x; //x的别名是r

    addPtr(p,5);
    cout<<x<<" "<<*p<<endl;
    addRef(r,5);
    cout<<x<<' '<<r<<' '<<*p<<endl;
    return 0;
}