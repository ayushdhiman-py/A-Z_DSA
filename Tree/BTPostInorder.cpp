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
    TreeNode *buildTree(vector<int> &postOrder, vector<int> &inorder)
    {
        // Store the indices of elements in inorder traversal for quick lookup
        map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i;
        }

        // Start building the tree
        return buildTreeHelper(postOrder, 0, postOrder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }

private:
    TreeNode *buildTreeHelper(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inOrder, int inStart, int in_end, map<int, int> &inorder_map)
    {
        if (postStart > postEnd || inStart > in_end)
        {
            return nullptr;
        }

        // Create a new node with the current postOrder element
        TreeNode *root = new TreeNode(postOrder[postEnd]); // Fix here, using postEnd instead of postStart

        // Find the index of the current root in the inorder traversal
        // inRoot is the index and not the value element
        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart;
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(postOrder, postStart, postStart + numsLeft - 1, inOrder, inStart, inRoot - 1, inorder_map);
        root->right = buildTreeHelper(postOrder, postStart + numsLeft, postEnd - 1, inOrder, inRoot + 1, in_end, inorder_map); // Fix here, update postStart + numsLeft

        return root;
    }
};

void printPreorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main()
{
    Solution solution;

    // Example usage:
    vector<int> post = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(post, inorder);

    // Print the inorder traversal of the constructed tree
    cout << "Post traversal of the constructed tree: ";
    printPreorder(root);

    return 0;
}
