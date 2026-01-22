/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, temp = 0;
        solve(root, ans, temp, k);
        return ans;
    }
    void solve(TreeNode* root, int& ans, int& temp, int k) {
        if (!root) return;

        if(root->left){
            TreeNode* muddy = root->left;
            while (muddy->right && muddy->right != root) muddy = muddy->right;

            if(muddy->right==NULL){ 
                muddy->right=root;
                solve(root->left,ans,temp,k);
            }else{
                temp++;
                if(temp==k) ans=root->val;
                muddy->right=NULL;
                solve(root->right,ans,temp,k);
            }
        }else{
            temp++;
            if (temp == k) ans = root->val;
            solve(root->right,ans,temp,k);
        }
    }
};