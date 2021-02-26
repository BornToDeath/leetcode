#include <iostream>
#include <vector>
using namespace std;

/**
  * 参考：https://zhuanlan.zhihu.com/p/308364408
  */


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> & candidates, int target) {
        combination(candidates, target, 0, 0);
        return res;
    }

private:
    void combination(vector<int> & candidates, int target, int sum, int index) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.emplace_back(path);
            return;
        }
        
        for (int i=index; i<candidates.size(); ++i) {
            path.emplace_back(candidates[i]);
            sum += candidates[i];
            combination(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }

    }

private:
    vector<vector<int>> res;
    vector<int> path;

};

void test01() {
    vector<int> candidates = {2,3,5};
    int target = 8;
    Solution s;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (const auto & path: res) {
        for (const auto & num: path) {
            cout << num << ", ";
        }
        cout << endl;
    }
}

int main(){
    test01();
    return 0;
}
