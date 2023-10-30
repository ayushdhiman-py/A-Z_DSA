
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

    bool isLeaf(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return true;
        }
        return false;
    }

    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }

    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }   

    void bt(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        for (int val : res)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    fast;

    TreeNode *root = new TreeNode(20);

    root->left = new TreeNode(8);
    root->right = new TreeNode(22);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(25);

    root->bt(root);
        
    delete root;

    return 0;
}
