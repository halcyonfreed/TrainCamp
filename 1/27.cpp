#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; 
        // for (int fast = 0; fast <= nums.size()-1; fast++){ //这样写， nums=[] 就会报错，runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
        for (int fast = 0; fast < nums.size(); fast++){
            if (val != nums[fast]){
                // 如果不等于,那么不删不跳过,所以赋值
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
int main(){
    vector<int> nums;
    int num,target;
    while(cin>>num){
        nums.push_back(num);
        if (getchar() == '\n') break;
    }
    cin>>target;
    cout<< Solution().removeElement(nums,target)<<endl;
    return 0;
}
