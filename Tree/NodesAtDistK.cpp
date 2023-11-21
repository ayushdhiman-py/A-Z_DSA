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

    void markparents(Node *root, unordered_map<Node *, Node *> &parentNodes, Node *target)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parentNodes[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parentNodes[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    void printNodes(Node *root, Node *target, int k)
    {
        unordered_map<Node *, Node *> parentNodes;
        markparents(root, parentNodes, target);

        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (dist++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                Node *crr = q.front();
                q.pop();
                if (crr->left && !visited[crr->left])
                {
                    q.push(crr->left);
                    visited[crr->left] = true;
                }
                if (crr->right && !visited[crr->right])
                {
                    q.push(crr->right);
                    visited[crr->right] = true;
                }
                if (parentNodes[crr] && !visited[parentNodes[crr]])
                {
                    q.push(parentNodes[crr]);
                    visited[parentNodes[crr]] = true;
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            res.push_back(n->data);
        }

        for (auto &a : res)
        {
            cout << a << " ";
        }
    }
};

int main()
{
    fast;

    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->right->left = new Node(0);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->right = new Node(8);

    root->printNodes(root, root->left, 2);
    // Clean up memory
    delete root;

    return 0;
}
