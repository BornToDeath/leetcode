#include <iostream>
#include <vector>

using namespace std;


class Solution{

public:

    vector<int> searchRange(vector<int> & nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        vector<int> res = {-1, -1};
        this->searchRange(nums, start, end, target, res);
        return res;
    }

private:

    void searchRange(const vector<int> & nums, int start, int end, const int target, vector<int> &res){
        if (start > end){
            return;
        }

        int mid = start + ((end-start) >> 1);

        if (nums[mid] == target){
            if (res[0] == -1) {
                res[0] = mid; 
            }
            if (res[1] == -1) {
                res[1] = mid;
            }
            res[0] = (mid < res[0]) ? mid : res[0];
            res[1] = (mid > res[1]) ? mid : res[1];
            searchRange(nums, start, mid-1, target, res);
            searchRange(nums, mid+1, end, target, res);
        } else {
            if (nums[mid] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            searchRange(nums, start, end, target, res);
        }
        
    }

};


int main(int argc, char * argv[]){

    //vector<int> nums = {5,7,7,8,8,10};
    vector<int> nums = {};
    int target = 0;

    Solution s;
    vector<int> res = s.searchRange(nums, target);
    
    cout << "["
         << res[0] 
         << ", "
         << res[1]
         << "]"
         << endl;

    return 0;
}
