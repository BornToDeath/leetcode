#include <iostream>

#include "ListNode.h"

using namespace std;




class Solution{

public:
    
    bool hasCycle(ListNode* head){
        
        ListNode* l1 = head;
        ListNode* l2 = head;

        while(nullptr != l2){
            
            l1 = l1->next;

            l2 = l2->next;

            if (nullptr != l2){
                l2 = l2->next;
                    if( l1 == l2 ){
                        return true;
                    }
            }

        }
        
        return false;

    }
    
};



int main(int argc, char* argv[]){
    
    ListNode* head = new ListNode(3);
    ListNode* node1 = head->next = new ListNode(2);
    node1->next = new ListNode(0);
    node1->next->next = new ListNode(-4);
    //node1->next->next->next = node1;
    
    Solution s;
    bool res = s.hasCycle(head);

    cout << res << endl;

    return 0;
}
