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
    bool fun(TreeNode* root){

        if(root==NULL) return true;
        bool null_found=false;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* t= q.front();
            q.pop();

            if(t==NULL){
                null_found=true;
            }
            else{
                if(null_found){  //means true
                    return false;
                }
                q.push(root->left);
                q.push(root->right);
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        bool null_found=false;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* t= q.front();
            q.pop();

            if(t==NULL){
                null_found=true;
            }
            else{
                if(null_found){  //means true
                    return false;
                }
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true; 
    }
};