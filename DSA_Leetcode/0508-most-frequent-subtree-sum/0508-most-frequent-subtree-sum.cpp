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
    int treesum(unordered_map<int,int>&mp, TreeNode* node){
        if(node == NULL) return 0;

        int l = treesum(mp, node->left);
        int r = treesum(mp, node->right);

        mp[l + r + node->val]++;

        return l + r + node->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>m;
        vector<int>ans;
        treesum(m, root);
        int maxfreq = 0;
        for(auto it : m){
            maxfreq = max(maxfreq, it.second);
        }
        for(auto it : m){
            if(it.second == maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};