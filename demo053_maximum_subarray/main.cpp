#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution{
    
public:
    int maxSubArray(vector<int>& nums){

        /**
          * 方法2
          */
        int maxSum = INT_MIN;
        int curSum = 0;
        for (int i=0;i<nums.size();++i){
            if (curSum <= 0){
                curSum = nums[i];
            }else{
                curSum += nums[i];
            }
            if(curSum > maxSum){
                maxSum = curSum;
            }
        }
        return maxSum;

        /**
          * 方法1
          */
        /*
        int size = nums.size();
        vector<int> dp(size);

        for(int i=0;i<size;++i){
            if (i == 0){
                dp[i] = nums[i];
                continue;
            }
            int tempSum = dp[i-1] + nums[i];
            if (tempSum >= 0){
                if ( tempSum < nums[i] ){
                    dp[i] = nums[i];
                } else {
                    dp[i] = tempSum;
                }
            } else {
                dp[i] = nums[i];
            }

        }
        
        //printArray(dp);

        int maxSum = dp[0];
        for (auto &num : dp){
            if (maxSum < num){
                maxSum = num;
            }
        }
        
        return maxSum;
        */
    }

    /**
      * 打印数组
      */
    void printArray(vector<int> &nums){
        for (auto &num : nums){
            cout << num << "\t";
        }
        cout << endl;
    }

};


int main(int argc, char* args[]){

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution s;
    int res = s.maxSubArray(nums);

    cout << res << endl;


    return 0;
}
