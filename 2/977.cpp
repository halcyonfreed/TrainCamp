#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 要返回result，自己要设一个vector存result; 从两边开始最大开始更新，递减
        int k = nums.size()-1; // 更新result的下标
        vector<int> result(nums.size(), 0); // vecto初始化不会，确定长度和内容=0
        
        // 定长，用for来遍历
        for(int left=0, right = nums.size() - 1; left <= right;){
            // left=right要处理，所以<=; 第三个分号没写因为要分情况！！ 第二个分号会因为第三个没写漏掉！！
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                // vector已经初始化值了，就不用pushback动脑子，直接改值
                result[k--] = nums[left] * nums[left];
                left++;
            }
            else{
                result[k--] = nums[right] * nums[right];
                right --;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    int num;
    while(cin>> num){
        // if(getchar()=='\n') break; //放这里最后一个元素就读不进来了；getchar不等待回车，直到缓冲区中的字符读完为后，才等待用户按键
        nums.push_back(num);
        if(getchar()=='\n') break; //位置重要
        // cout<< num<<endl;
    }

    // vector不可以直接输出
    // cout << Solution().sortedSquares(nums) <<endl;
    vector<int> result=Solution().sortedSquares(nums);
    // cout<<result.size()<<' '<< nums.size()<<endl;
    for(int i=0; i<nums.size();i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;


    // 测试getchar()
    while(cin>>num){
        // 输入缓冲区，同时num已经从缓冲区里取走了
        cout<<num<<endl;
        cout<< getchar()<<endl;
        cout<<endl;
    }
    return 0;
}
