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

    // DFS //
    void inorderTraversal(Node *root)
    {
        if (!root)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
    void postorderTraversal(Node *root)
    {
        if (!root)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
    void preorderTraversal(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    // DFS //

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

    // ----- DEPTH ORDER TRAVERSAL ( DFS )----- //

    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->right = new Node(4);

    // cout << "In-order traversal: ";
    // root->inorderTraversal(root);
    // cout << endl;
    // root->postorderTraversal(root);
    // cout << endl;
    // root->preorderTraversal(root);
    // cout << endl;

    // ----- LEVEL ORDER TRAVERSAL ( BFS )----- //

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->levelOrderTraversal(root);

    // Clean up memory
    delete root;

    return 0;
}
