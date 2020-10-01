#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> & nums);

class Solution{

public:

    vector<int> findDisappearedNumbers(vector<int> & nums){
    
        for(int i=0; i<nums.size(); ){
            
            int index = nums[i] - 1;

            if(nums[i] == nums[index]){
                ++i;
                continue;
            }

            nums[i] += nums[index];
            nums[index] = nums[i] - nums[index];
            nums[i] = nums[i] - nums[index];

        }

        vector<int> res;

        for(int i=0;i<nums.size();++i){
            if(i+1 != nums[i]){
                res.emplace_back(i+1);
            }
        }

        return res;
    }

};

void printArray(vector<int> & nums){

    for(auto & num: nums){
        cout << num << ", ";
    }
    cout << endl;

}

int main(){

    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution s;

    vector<int> res = s.findDisappearedNumbers(nums);

    printArray(nums);

    printArray(res);

    return 0;
}
