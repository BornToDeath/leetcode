#include <iostream>
#include <vector>

using namespace std;


class Solution{
    
public:
    
    int majorityElement(vector<int>& nums){
        /**
          * 思路1：使用map。
          * map存储每个元素出现的次数，遍历map查找出现次数最多的元素。
          */

        /**
          * 思路2：排序。
          * 先对数组进行排序，之后取中间的元素。
          */
        
        /**
          * 思路3：只遍历一遍
          */
        int candidate = 0;
        int count = 0;

        for (auto & num: nums){
            if (count == 0){
                candidate = num;
            }
            count += ((candidate == num) ? 1 : -1);
        }
        return candidate;
    }

};



int main(int argc, char* argv[]){

    vector<int> nums = {2,2,1,1,1,2,2};

    Solution s;
    int res = s.majorityElement(nums);

    cout << res << endl;

    return 0;
}
