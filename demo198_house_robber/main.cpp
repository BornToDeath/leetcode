#include <iostream>
#include <vector>

using namespace std;



class Solution{

public:

    int rob(vector<int> & nums){
    
        /**
          * 思路1：使用动态规划
          * money(i) = max(money(i-1), money(i-2)) + nums[i];
          */

        /**
          * 思路2：使用两个变量保存当前和上次最大收益
          */
        int preMaxMoney = 0;
        int curMaxMoney = 0;
        
        for (auto & num: nums){
            int temp = (curMaxMoney > preMaxMoney + num) ? curMaxMoney : preMaxMoney + num;
            preMaxMoney = curMaxMoney;
            curMaxMoney = temp;
        }
        return (preMaxMoney > curMaxMoney) ? preMaxMoney : curMaxMoney;

    }

};



int main(){

    //vector<int> nums = {1,2,3,1};
    vector<int> nums = {2,7,9,3,1};

    Solution s;
    int res = s.rob(nums);
    
    cout << res << endl;

    return 0;
}
