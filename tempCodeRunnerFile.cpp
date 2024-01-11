#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int removeElement(vector<int>& nums, int target){
        int slow=0;
        for(int fast=0; fast < nums.size(); ++fast){
            if(target != nums[fast]) nums[slow++]=nums[fast];
        }
        return slow;
    }
};

int main(){
    vector<int> nums;
    int num, target;
    while(cin >> num){
        if(getchar() == '\n') break;
        nums.push_back(num);
    }

    cin >> target;

    cout << Solution().removeElement(nums,target) << endl;
    return 0;
}