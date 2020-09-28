#include <iostream>
#include "TreeNode.h"

using namespace std;



class Solution{

public:

    TreeNode* invertTree(TreeNode* root){
    
        /**
          * 思路1：递归
          */
        invert(root);
        return root;
        
        /**
          * 思路2：循环
          * 如果当前节点存在叶子节点，则交换它们
          */


    }

    void invert(TreeNode* root){
        
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            return ;
        }

        if(root->left != nullptr && root->right != nullptr){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
        }else if(root->left == nullptr){
            root->left = root->right;
            root->right = nullptr;
        }else{
            root->right = root->left;
            root->left = nullptr;
        }

        invert(root->left);
        invert(root->right);

    }

};


void printTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main(){

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    printTree(root);

    Solution s;
    TreeNode* res = s.invertTree(root);
    
    cout << "**************" << endl;

    printTree(res);

    return 0;
}
