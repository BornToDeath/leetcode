#include <iostream>
#include "ListNode.h"

class Solution {

public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *head = new ListNode(-1);
        ListNode *cur = head;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }

        if (carry != 0) {
            cur->next = new ListNode(1);
        }

        return head->next;
    }

};

void test01() {

    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    l2->next->next->next->next = new ListNode(9);

    Solution s;
    ListNode *res = s.addTwoNumbers(l1, l2);

    while (res != nullptr) {
        std::cout << res->val << ", ";
        res = res->next;
    }
    std::cout << std::endl;
}

int main() {

    test01();
    return 0;
}
