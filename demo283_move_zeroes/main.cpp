#include <iostream>
#include <vector>

using namespace std;


class Solution{

public:

    void moveZeroes(vector<int> & nums){
        
        int zeroIndex = 0;
        int nonZeroIndex = 0;

        int len = nums.size();
        while(nonZeroIndex < len){
            while(nonZeroIndex < len && nums[nonZeroIndex] == 0){
                ++nonZeroIndex;
            }

            if(nonZeroIndex >= len){
                break;
            }

            nums[zeroIndex] = nums[nonZeroIndex];

            ++zeroIndex;
            ++nonZeroIndex;
        }

        while(zeroIndex < len){
            nums[zeroIndex] = 0;
            ++zeroIndex;
        }

    }

};


void printArray(vector<int> & nums){
    
    for (auto & num : nums){
        cout << num << " ";
    }
    cout << endl;

}


int main(){

    vector<int> nums = {0,1,0,3,12};
    vector<int> nums2 = {0,0,0,0};

    Solution s;

    printArray(nums2);

    s.moveZeroes(nums2);

    printArray(nums2);
    
    return 0;
}
