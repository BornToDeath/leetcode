#include <iostream>
#include "ListNode.h"

using namespace std;



class Solution{

public:

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        
        ListNode* node1 = headA;
        ListNode* node2 = headB;

        while (nullptr != node1 && nullptr != node2){
            if(node1 == node2){
                return node1;
            }
            node1 = node1->next;
            node2 = node2->next;

            if (nullptr == node1 && nullptr == node2){
                return nullptr;
            }

            if(nullptr == node1){
                node1 = headB;
            }

            if (nullptr == node2){
                node2 = headA;
            }
        }
        return nullptr;

    }

};



int main(int argc, char* argv[]){

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    ListNode* node = headA->next->next->next = new ListNode(9);
    node->next = new ListNode(9);
    node->next->next = new ListNode(9);

    ListNode* headB = new ListNode(1);
    headB->next = node;

    Solution s;
    ListNode* iNode = s.getIntersectionNode(headA, headB);

    cout << iNode->val << endl;


    return 0;
}
