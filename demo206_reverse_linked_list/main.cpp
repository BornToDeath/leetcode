#include <iostream>

#include "ListNode.h"

using namespace std;



class Solution{

public:

    ListNode* reverseList(ListNode* head){
        
        /**
          * 思路1：循环
          */
        /*
        ListNode* rHead = nullptr;

        ListNode* curNode = head;
        ListNode* nextNode = nullptr;

        while(curNode != nullptr){
            nextNode = curNode->next;
            curNode->next = rHead;
            rHead = curNode;
            curNode = nextNode;
        }

        return rHead;
        */

        
        /**
          * 思路2：递归
          */
        
        return reverse(head, nullptr);

    }

private:
    ListNode* reverse(ListNode* head, ListNode* pre){

        if (head == nullptr){
            return head;
        }

        if (head->next == nullptr){
            head->next = pre;
            return head;
        }

        ListNode* next = head->next;
        head->next = pre;

        return reverse(next, head);

    }


};



int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    
    Solution s;
    ListNode* rHead = s.reverseList(head);


    ListNode* temp = rHead;
    while(temp != nullptr){
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
