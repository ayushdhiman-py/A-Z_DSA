#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }

    void changeTree(Node *root)
    {
        if (!root)
            return;
        int child = 0;
        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;

        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = root->data;
            if (root->right)
                root->right->data = root->data;
        }
        changeTree(root->left);
        changeTree(root->right);
        int total = 0;
        if (root->left)
            total += root->left->data;
        if (root->right)
            total += root->right->data;
        if (root->left || root->right)
            root->data = total;
    }

    // BFS //
    void levelOrderTraversal(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                temp.push_back(node->data);
            }
            ans.push_back(temp);
        }

        for (auto &it : ans)
        {
            for (auto &ele : it)
            {
                cout << ele << " ";
            }
            cout << "\n";
        }
    }
    // BFS //
};

int main()
{
    fast;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->levelOrderTraversal(root);
    cout << "\n";
    root->changeTree(root);
    cout << "\n";
    root->levelOrderTraversal(root);

    // Clean up memory
    delete root;

    return 0;
}
