#include <iostream>
using namespace std;


class Solution{

public:
    
    int climbStairs(int n){

        /**
          * 方法2
          */
        int res;

        if (n <= 1){
            res = 1;
        }
        if (n == 2){
            res = 2;
        }

        int prepre = 1;
        int pre = 2;
        
        for (int i=3;i<=n;++i){
            res = prepre + pre;
            prepre = pre;
            pre = res;
        }
        return res;


        /**
          * 方法1。超过时间限制
          */
        if (n <= 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }

};



int main(int argc, char* argv[]){
    
    if (argc <= 1){
        cout << "Error: the number of arguments is illegal!" << endl;
        return -1;
    }

    int n = stoi(argv[1]);

    Solution s;
    int res = s.climbStairs(n);
    
    cout << res << endl;


    return 0;
}
