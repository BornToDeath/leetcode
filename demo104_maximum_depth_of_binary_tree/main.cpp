#include <iostream>

#include "TreeNode.h"

using namespace std;

class Solution{

public:
    int maxDepth(TreeNode* root){
        /**
          * 方法2：循环
          * 遍历每一层的所有节点，如果有下层节点就加入到队列中，
          * 同时高度+1，直到叶子节点。
          */


        /**
          * 方法1：递归
          */
        if (nullptr == root){
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (leftDepth > rightDepth) ? (1 + leftDepth) : (1 + rightDepth);
    }

};


int main(int argc, char* argv[]){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new  TreeNode(7);

    Solution s;
    int depth = s.maxDepth(root);

    cout << depth << endl;

    return 0;
}
