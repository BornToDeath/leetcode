#include <iostream>
#include "ListNode.h"

using namespace std;


class Solution{

public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        
        ListNode* resHead = new ListNode(-1);
        ListNode* res = resHead;

        ListNode* templ1 = l1;
        ListNode* templ2 = l2;

        while(templ1 != nullptr && templ2 != nullptr){
            
            if(templ1->val <= templ2->val){
                res->next = templ1;
                templ1 = templ1->next;
            } else {
                res->next = templ2;
                templ2 = templ2->next;
            }
            res = res->next;
        }

        if (templ1 !=  nullptr) {
            res->next = templ1;
        }

        if (templ2 != nullptr) {
            res->next = templ2;
        }

        return resHead->next;

    }

};


void freeList(ListNode* list){
    ListNode* temp = list;
    while(temp != nullptr){
        list = temp;
        temp = list->next;
        delete list;
        list = nullptr;
    }
}


int main(int argc, char* argv[]){
    
    ListNode* l10 = new ListNode(1);
    ListNode* l11 = l10->next = new ListNode(2);
    ListNode* l12 = l11->next = new ListNode(4);

    ListNode* l20 = new ListNode(1);
    ListNode* l21 = l20->next = new ListNode(3);
    ListNode* l22 = l21->next = new ListNode(4);

    Solution s;
    ListNode* res = s.mergeTwoLists(l10, l20);

    ListNode* templ = res;
    while(templ != nullptr){
        cout << templ->val << endl;
        templ = templ -> next;
    }

    freeList(res);

    return 0;
}
