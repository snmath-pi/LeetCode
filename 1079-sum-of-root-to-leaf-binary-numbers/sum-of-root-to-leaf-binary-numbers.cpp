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
    int calc(string& s) {
        cout << s << '\n';
        int n = (int) s.size();
        int val = 0;

        for (int i = 0; i < n; i++) {
            val += (s[i] - '0') * (1 << (n - i - 1));
        }
        return val;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s;

        int ans = 0;
        auto dfs = [&](TreeNode* node, auto&& dfs) -> void {
            
            s += (node->val + '0');
            if (node->left) dfs(node->left, dfs);
            if (node->right) dfs(node->right, dfs);
            if (!node->left && !node->right) ans += calc(s);
            s.pop_back();
        };

        dfs(root, dfs);

        return ans;
    }
};