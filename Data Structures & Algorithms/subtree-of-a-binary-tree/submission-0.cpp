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
    bool subTreeMatch(TreeNode* root, TreeNode* subRoot){
        
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root != nullptr && subRoot != nullptr){ 
            if (subRoot->val == root->val) return subTreeMatch(root->left, subRoot->left) && subTreeMatch(root->right, subRoot->right);
            else return false;
        }
        else return false;
        
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;
        if(root->val == subRoot->val && subTreeMatch(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
