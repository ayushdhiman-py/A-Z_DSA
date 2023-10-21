
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }

    // NAIVE SOLUTION
    // bool check(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return true;
    //     int Lh = findHLeft(root->left);
    //     int Rh findHRight(root->right);
    //     if (abs(Rh - Lh) > 1)
    //         return false;
    //     bool left = check(root->left);
    //     bool right = check(root->right);
    //     if (left || right)
    //         return false;
    //     return true;
    // }

    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lHeight = dfsHeight(root->left);
        if (lHeight == -1)
        {
            return -1;
        }

        int rHeight = dfsHeight(root->right);
        if (rHeight == -1)
        {
            return -1;
        }

        if (abs(lHeight - rHeight) > 1)
        {
            return -1; // Changed from 'return false;' to 'return -1;'
        }

        return max(lHeight, rHeight) + 1;
    }

    void isBalanced(TreeNode *root)
    {
        cout << boolalpha << (dfsHeight(root) != -1) << endl; // Used 'boolalpha' to display boolean output
    }
};

int main()
{
    fast;

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->left->left = new TreeNode(3);

    root->isBalanced(root);

    delete root;

    return 0;
}
