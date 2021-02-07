#include <iostream>
#include <vector>
using namespace std;


class Solution {
    
public:

    int lengthOfLongestSubstring (string s) {
        
        vector<int> mapping(128, -1);

        int maxLen = 0;
        int curLen = 0;
        for (int i = 0;i < s.size();++i) {
            int index = mapping[s[i]];
            mapping[s[i]] = i;
            if (index == -1 || i - index > curLen) {
                ++curLen;
            } else {
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
                curLen = i - index;
            }
        }
        if (curLen > maxLen) {
            maxLen = curLen;
        }

        return maxLen;
    }

};


int main() {

    //string str("abcabcbb");
    //string str("bbbbbb");
    //string str("abcdejgnslorg");
    //string str(" ");
    string str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    Solution s;
    
    int len = s.lengthOfLongestSubstring(str);
    cout << len << endl;
    
    return 0;
}
