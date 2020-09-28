#include <iostream>
#include <string>
#include <vector>

#include "ListNode.h"

using namespace std;


class Solution{

public:

    bool isPalindrome(ListNode* head){
        
        /**
          * 思路2：
          * 1. 快慢指针获取链表中间位置
          * 2. 从中间位置遍历链表，构建其反向链表
          * 3. 从头分别比较head和反向链表对应的值
          */

        /**
          * 思路1：借助vector。
          * 遍历 head ，使用vector存储所有元素，然后分别从首尾遍历vector判断对应的值是否相等
          */

        vector<int> vv;
        
        while(head != nullptr){
            vv.push_back(head->val);
            head = head->next;
        }

        int len = vv.size();

        int i = 0;
        int j = len - 1;

        while(i < j){
            if(vv[i] == vv[j]){
                ++i;
                --j;
            }else{
                return false;
            }
        }
        
        return true;
    
    }

};



int main(){

    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    ListNode* head1 = new ListNode(-1);
    head->next = new ListNode(-1);

    Solution s;
    
    cout << s.isPalindrome(head) << endl;
    cout << s.isPalindrome(head1) << endl;

    return 0;
}
