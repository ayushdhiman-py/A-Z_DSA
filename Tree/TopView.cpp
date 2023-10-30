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
    void topView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return;
        map<int, int> mpp;
        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
                mpp[line] = node->data;
            if (node->left)
            {
                q.push({node->left, line - 1});
            }
            if (node->right)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto &it : mpp)
        {
            ans.push_back(it.second);
        }

        for (auto &it : ans)
        {
            cout << it << " ";
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
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    root->topView(root);

    // Clean up memory
    delete root;

    return 0;
}