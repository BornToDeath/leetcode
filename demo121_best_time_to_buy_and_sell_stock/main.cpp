#include <iostream>
#include <vector>
#include <climits>
using namespace std;



class Solution{

public:
    int maxProfit(vector<int>& prices){
        
        int profit = 0;

        int minPrice = INT_MAX;

        for (auto& price: prices){
            if (price < minPrice){
                minPrice = price;
                continue;
            }
            if (price - minPrice > profit){
                profit = price - minPrice;
            }
        }

        return profit;

    }

};



int main(int argc, char* argv[]){

    //vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices = {7,6,5,3,2,1};

    Solution s;
    int maxProfit = s.maxProfit(prices);

    cout << maxProfit << endl;
    
    return 0;
}
