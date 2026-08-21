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
    unordered_map<int, int> in;
    int index = 0;

    TreeNode* fun(vector<int>& preorder, int low, int high){
        if(low>high) return NULL;
        TreeNode* node = new TreeNode(preorder[index]);
        index++;

        int id=in[node->val];
        node->left = fun(preorder, low, id-1);     // left subtree 
        node->right = fun(preorder, id+1, high);   // right subtree 
        return node; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        for(int i=0; i<inorder.size(); i++){
            in[inorder[i]] = i;
        }
        return fun(preorder, 0, inorder.size()-1);
    }
};