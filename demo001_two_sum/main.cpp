#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution{

public:

    vector<int> twoSum(vector<int>& nums, int target){
                
        unordered_map<int, int> umap;
        for(int i=0;i<nums.size();++i){
            int matchNum = target - nums[i];
            if(umap.find(matchNum) != umap.end()){
                return {umap[matchNum], i};
            }else{
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};


int main(int argc, char* args[]){
    
    vector<int> nums = {7,2,11,15};
    //vector<int> nums;
    int target = 9;
    
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    
    for(auto v: res){
        cout << v << endl;
    }
    
    return 0;
}
