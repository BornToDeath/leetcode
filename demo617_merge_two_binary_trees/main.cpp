#include <iostream>
#include <queue>

#include "TreeNode.h"

using namespace std;



class Solution{

public:

    TreeNode * mergeTrees(TreeNode * t1, TreeNode * t2){
        
        /**
          * 方法2：递归处理
          */

        if(!t1){
            return t2;
        }

        if(!t2){
            return t1;
        }

        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;

        /**
          方法1：循环处理，如果当前t1、t2都有左右节点，则将t1、t2左右节点
          分别存储在各自队列中，直到队列为空。
        */

        /*
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        
        if(t1 == nullptr){
            return t2;
        }
        
        if(t2 == nullptr){
            return t1;
        }

        q1.push(t1);
        q2.push(t2);

        while(!q1.empty()){

            TreeNode * node1 = q1.front();
            q1.pop();

            TreeNode * node2 = q2.front();
            q2.pop();

            node1->val += node2->val;

            if(node1->left && node2->left){
                q1.push(node1->left);
                q2.push(node2->left);
            }else if(node1->left == nullptr){
                node1->left = node2->left;
            }

            if(node1->right && node2->right){
                q1.push(node1->right);
                q2.push(node2->right);
            }else if(node1->right == nullptr){
                node1->right = node2->right;
            }

        }

        return t1;
        */
    }

private:

    void merge2Node(TreeNode * & t1, TreeNode * & t2){
        t1->val += t2->val;
    }

};


void printBinaryTree(TreeNode * root){
    
    if(root == nullptr){
        return;
    }

    queue<TreeNode *> q;

    q.push(root);
    
    TreeNode * temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    cout << endl;
}


int main(){

    TreeNode * root1  = new TreeNode(1);
    root1->left       = new TreeNode(3);
    root1->right      = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    printBinaryTree(root1);

    TreeNode * root2    = new TreeNode(2);
    root2->left         = new TreeNode(1);
    root2->right        = new TreeNode(3);
    root1->left->right  = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    printBinaryTree(root2);

    Solution s;
    
    TreeNode * res = s.mergeTrees(root1, root2);

    printBinaryTree(res);


    return 0;
}
