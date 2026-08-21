class Solution {
public:
    int galat = 0;

    TreeNode* prev = NULL;

    TreeNode* g1first = NULL;
    TreeNode* g1second = NULL;

    TreeNode* g2first = NULL;
    TreeNode* g2second = NULL;

    void fun(TreeNode* root){

        if(root == NULL)
            return;

        fun(root->left);

        if(prev == NULL){
            prev = root;
        }
        else{
            if(root->val < prev->val){

                if(galat == 0){
                    g1first = prev;
                    g1second = root;
                }
                else{
                    g2first = prev;
                    g2second = root;
                }

                galat++;
            }

            prev = root;
        }

        fun(root->right);
    }

    void recoverTree(TreeNode* root) {

        fun(root);

        if(galat == 1){
            swap(g1first->val, g1second->val);
        }
        else{
            swap(g1first->val, g2second->val);
        }
    }
};