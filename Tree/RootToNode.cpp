#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class TreeNode
{
public:
    TreeNode *left, *right;
    int data;

    TreeNode(int val)
    {
        left = right = NULL;
        data = val;
    }

    bool getPath(TreeNode *root, int target, vector<int> &res)
    {
        if (!root)
            return false;

        res.push_back(root->data);

        if (root->data == target)
            return true;

        if (getPath(root->left, target, res) || getPath(root->right, target, res))
            return true;

        res.pop_back();
        return false;
    }

    void RootToNode(TreeNode *root, int target)
    {
        vector<int> res;

        if (!root)
            return;

        getPath(root, target, res);

        for (auto &ele : res)
        {
            cout << ele << " ";
        }
    }
};

int main()
{

    fast;
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->RootToNode(root, 7);

    // Clean up memory
    delete root;

    return 0;
}