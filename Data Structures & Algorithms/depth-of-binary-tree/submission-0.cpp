/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void computeMaxDepth(TreeNode* root, int currentDepth, int &maxDepth){
        if(root->left == nullptr && root->right == nullptr){
            maxDepth = max(currentDepth, maxDepth);
        }else{
            if(root->left != nullptr) computeMaxDepth(root->left, currentDepth + 1, maxDepth);
            if(root->right != nullptr) computeMaxDepth(root->right, currentDepth + 1, maxDepth);
        }
    }

    int maxDepth(TreeNode* root) {
        int maxDepth=0;
        if (root == nullptr) return 0;
        computeMaxDepth(root, 1, maxDepth);
        return maxDepth;
    }
};
