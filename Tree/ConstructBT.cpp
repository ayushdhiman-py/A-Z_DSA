#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preOrder, vector<int> &inorder)
    {
        // Store the indices of elements in inorder traversal for quick lookup
        map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i;
        }

        // Start building the tree
        return buildTreeHelper(preOrder, 0, preOrder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }

private:
    TreeNode *buildTreeHelper(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int in_end, map<int, int> &inorder_map)
    {
        if (preStart > preEnd || inStart > in_end)
        {
            return nullptr;
        }

        // Create a new node with the current preOrder element
        TreeNode *root = new TreeNode(preOrder[preStart]);

        // Find the index of the current root in the inorder traversal
        // inRoot is the index and not the value element
        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart;
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inorder_map);

        root->right = buildTreeHelper(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, in_end, inorder_map);

        return root;
    }
};

// Helper function to print the inorder traversal of the tree
void printPostorder(TreeNode *root)
{
    if (root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    Solution solution;

    // Example usage:
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(preOrder, inorder);

    // Print the inorder traversal of the constructed tree
    cout << "Post traversal of the constructed tree: ";
    printPostorder(root);

    return 0;
}
