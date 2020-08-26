#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;


class Solution{

public:

    bool isSymmetric(TreeNode* root){
       
        /**
          * 方法2：循环
          */
        if (nullptr == root){
            return true;
        }

        queue<TreeNode*> qLeft;
        queue<TreeNode*> qRight;
        
        qLeft.push(root->left);
        qRight.push(root->right);
        
        TreeNode* lNode;
        TreeNode* rNode;
        while (!qLeft.empty() && !qRight.empty()){
            lNode = qLeft.front();
            rNode = qRight.front();
            
            qLeft.pop();
            qRight.pop();

            if (nullptr == lNode || nullptr == rNode){
                if(nullptr == lNode && nullptr == rNode){
                    continue;
                }
                return false;
            }

            if (lNode->val != rNode->val){
                return false;
            }

            // qLeft 从左到右入队列
            qLeft.push(lNode->left);
            qLeft.push(lNode->right);

            // qRight 从右到左入队列
            qRight.push(rNode->right);
            qRight.push(rNode->left);
        }

        if (!qLeft.empty() || !qRight.empty()){
            return false;
        }

        return true;



        /**
          * 方法1：递归
          */
        /*
        if (root == nullptr){
            return false;
        }

        return isSymmetricReal(root->left, root->right);
        */

    }

    bool isSymmetricReal(TreeNode* root1, TreeNode* root2){
        if (root1 == nullptr || root2 == nullptr){
            if(root1 == nullptr && root2 ==nullptr){
                return true;
            }
            return false;
        }
        //cout << ">>>root1: " << root1->val << endl;
        //cout << ">>>root2: " << root1->val << endl;
        if (root1->val == root2->val){
            return (isSymmetricReal(root1->left, root2->right) && isSymmetricReal(root1->right, root2->left));
        }
        return false;
    }


};


int main(int argc, char* argv[]){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(7);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(5);

    Solution s;
    bool res = s.isSymmetric(root);

    cout << res << endl;

    return 0;

}
