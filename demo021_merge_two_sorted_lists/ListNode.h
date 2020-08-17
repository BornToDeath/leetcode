
/**
  * 单链表节点结构定义
  */
struct ListNode{
    
    ListNode() : val(0), next(nullptr) {

    }

    ListNode(int x) : val(x), next(nullptr) {

    }

    ListNode(int x, ListNode* next) : val(x), next(next) {

    }

    int val;
    ListNode* next;

};
