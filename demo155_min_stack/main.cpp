#include <iostream>
#include <stack>
#include <climits>

using namespace std;


class MinStack{

public:

    MinStack(){
        
    }

    void push(int x){

        s.push(x);

        if (!minStack.empty()){
            int temp = minStack.top();
            if (temp < x){
                x = temp;
            }
        }
        minStack.push(x);

    }

    void pop(){
        if (!s.empty()){
            s.pop();
            minStack.pop();
        }

    }

    int top(){
        if (s.empty()){
            return INT_MIN;
        }
        return s.top();
    }

    int getMin(){
        if (s.empty()){
            return INT_MIN;
        }
        return minStack.top();
    }


private:

    stack<int> s;
    stack<int> minStack;

};


int main(int argc, char* argv[]){

    
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl; // return -3
    minStack->pop();
    cout << minStack->top() << endl;    // return 0
    cout << minStack->getMin() << endl; // return -2



    return 0;
}
