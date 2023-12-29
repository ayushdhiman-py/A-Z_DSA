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

    void morrisInorder(Node *root)
    {
        vector<int> inorder;
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        for (auto &it : inorder)
        {
            cout << it << " ";
        }
    }

    void morrisPreorder(Node *root)
    {
        vector<int> preorder;
        Node *curr = root;

        while (curr)
        {
            if (curr->left == NULL)
            {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        for (auto &it : preorder)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    fast;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    root->morrisInorder(root);
    cout << "\n";
    root->morrisPreorder(root);

    // Clean up memory
    delete root;

    return 0;
}
