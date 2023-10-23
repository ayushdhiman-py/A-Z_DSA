#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        findMax(root, maxSum);
        return maxSum;
    }

private:
    int findMax(TreeNode *node, int &maxSum)
    {
        if (!node)
            return 0;

        // Recursively calculate the max path sum of left and right subtrees
        int left = max(findMax(node->left, maxSum), 0);   // If negative, discard the path
        int right = max(findMax(node->right, maxSum), 0); // If negative, discard the path

        // The maximum path that uses the current node as its highest node
        int currentMax = node->val + left + right;

        // Update the result
        maxSum = max(maxSum, currentMax);

        // Return the max path sum that passes the current node
        return node->val + max(left, right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    delete root;
    return 0;
}
