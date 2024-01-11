#include<iostream>
#include<vector>
using namespace std;
// 看了题解，leetcode默一遍，vscode自己再写一遍
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
        if(getchar()=='\n') break;
        nums.push_back(num);
    }

    // vector不可以直接输出
    // cout << Solution().sortedSquares(nums) <<endl;
    cout<<Solution().sortedSquares(nums).size();
    for(int i=0; i<nums.size();i++){
        cout<<Solution().sortedSquares(nums)[i]<<' ';
    }
    cout<<endl;
    return 0;
}
