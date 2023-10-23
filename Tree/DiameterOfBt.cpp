#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int height(TreeNode *root, int &diameter)
{
    if (!root)
        return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

// naive
// int diameterNaive(TreeNode *root)
// {
//     if (!root)
//         return 0;

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     int leftDiameterNaive = diameterNaive(root->left);
//     int rightDiameterNaive = diameterNaive(root->right);

//     return max({1 + leftHeight + rightHeight, leftDiameterNaive, rightDiameterNaive});
// }

void diameter(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    cout << diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4); 
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(5);

    // cout << "DiameterNaive of the tree: " << diameterNaive(root) << endl;
    diameter(root);

    delete root;
    return 0;
}
