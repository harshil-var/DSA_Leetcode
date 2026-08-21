class Solution {
public:

    unordered_map<int,int> in;
    int index;

    TreeNode* fun(vector<int>& postorder, int low, int high){

        if(low > high)
            return NULL;

        TreeNode* node = new TreeNode(postorder[index--]);

        int id = in[node->val];

        // Build RIGHT first
        node->right = fun(postorder, id+1, high);
        node->left  = fun(postorder, low, id-1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++)
            in[inorder[i]] = i;

        index = postorder.size()-1;

        return fun(postorder,0,inorder.size()-1);
    }
};