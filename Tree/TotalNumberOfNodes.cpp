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

    int returnHeightLeft(Node *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }

    int returnHeightRight(Node *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }

    int CountNodes(Node *root)
    {
        if (root == NULL)
            return 0;
        int lh = returnHeightLeft(root);
        int rh = returnHeightRight(root);
        if (lh == rh)
            return (pow(2, lh) - 1);
        return 1 + CountNodes(root->left) + CountNodes(root->right);
    }
};

int main()
{
    fast;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(11);
    root->left->right->left = new Node(10);
    root->left->left->left = new Node(8);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    cout << root->CountNodes(root);
    // Clean up memory
    delete root;

    return 0;
}

// BELOW IS CODE OF O(n) COUNT TC
// #include <bits/stdc++.h>
// using namespace std;

// #define fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(nullptr);                 \
//     cout.tie(nullptr);

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }

//     int CountNodes(Node *root)
//     {
//         if (root == NULL)
//             return 0;

//         return 1 + CountNodes(root->left) + CountNodes(root->right);
//     }
// };

// int main()
// {
//     fast;

//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->left->right = new Node(7);
//     root->right = new Node(3);
//     root->right->left = new Node(5);
//     root->right->right = new Node(6);

//     cout << root->CountNodes(root) << endl;

//     // Clean up memory
//     delete root;

//     return 0;
// }
