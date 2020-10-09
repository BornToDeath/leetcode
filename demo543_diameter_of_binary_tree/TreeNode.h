

/**
  * Definition for a binary tree node.
  */
struct TreeNode{
    
    TreeNode(): val(0), left(nullptr), right(nullptr){
    
    }

    TreeNode(int x): val(x), left(nullptr), right(nullptr){
    
    }
    
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){
    
    }


    int val;
    TreeNode *left;
    TreeNode *right;

};
