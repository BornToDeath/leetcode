#include <iostream>
#include "TreeNode.h"
using namespace std;



class Solution{

public:
    
    int diameterOfBinaryTree(TreeNode * root){

        if(root == nullptr){
            return 0;
        }

        int height = 0;
        
        this->heightOfBinaryTree(root, height);
        
        return height;
    }

private:

    int heightOfBinaryTree(TreeNode * root, int & height){

        if(root == nullptr){
            return 0;
        }

        int leftHeight = heightOfBinaryTree(root->left, height);
        int rightHeight = heightOfBinaryTree(root->right, height);

        if(leftHeight + rightHeight > height){
            height = leftHeight + rightHeight;
        }

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

    }
};


int main(){

    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;

    int diameter = s.diameterOfBinaryTree(root);

    cout << diameter << endl;
    return 0;
}
