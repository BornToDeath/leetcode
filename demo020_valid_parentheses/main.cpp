#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution{

public:

    bool isValid(string s){

        unordered_map<char, char> umap;
        umap['('] = ')';
        umap['['] = ']';
        umap['{'] = '}';

        stack<char> sta;

        for(auto c: s){
            if (umap.find(c) != umap.end()){
                sta.push(umap[c]);
            }else{
                //只有右括号没有左括号
                if(sta.empty()){ 
                    return false;
                }
                //括号不匹配
                if(sta.top() != c){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
        
    }

};


int main(int argc, char* argv[]){
    
    string str = "()[]{}";

    Solution s;
    cout << s.isValid(str) << endl;

    return 0;
}

