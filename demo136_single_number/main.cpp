#include <iostream>
#include <vector>

using namespace std;


class Solution{
    
public:

    int singleNumber(vector<int>& nums){
        
        int res = 0;

        for (auto& num: nums){
            res ^= num;
        }
        return res;

    }

};



int main(int argc, char* argv[]){

    
    vector<int> nums = {2,2,1,3,3,1,6};

    Solution s;
    int singleNum = s.singleNumber(nums);

    cout << singleNum << endl;

    
    return 0;
}
