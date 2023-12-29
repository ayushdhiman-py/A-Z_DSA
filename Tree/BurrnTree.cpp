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

    Node *bfsMapParents(Node *node, map<Node *, Node *> &mpp, int start)
    {
        queue<Node *> q;
        q.push(node);
        Node *res;
        while (!q.empty())
        {
            Node *n = q.front();
            if (n->data == start)
            {
                res = n;
            }
            q.pop();
            if (n->left)
            {
                mpp[n->left] = n;
                q.push(n->left);
            }
            if (n->right)
            {
                mpp[n->right] = n;
                q.push(n->right);
            }
        }
        return res;
    }
    // Node<int> *bfsMapParents(Node<int> *node, map<Node<int> *, Node<int> *> &mpp, int start)
    // {
    //     queue<Node<int> *> q;
    //     q.push(node);
    //     Node<int> *res;
    //     while (!q.empty())
    //     {
    //         Node<int> *n = q.front();
    //         if (n->data == start)
    //         {
    //             res = n;
    //         }
    //         q.pop();
    //         if (n->left)
    //         {
    //             mpp[n->left] = n;
    //             q.push(n->left);
    //         }
    //         if (n->right)
    //         {
    //             mpp[n->right] = n;
    //             q.push(n->right);
    //         }
    //     }
    //     return res;
    // }

    void BurnTree(Node *root, int start)
    {
        map<Node *, Node *> mpp;
        Node *target = bfsMapParents(root, mpp, start);
        cout << target->data;
    }
};

int main()
{
    fast;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->BurnTree(root, 2);
    // Clean up memory
    delete root;

    return 0;
}
