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

    void iterativePreorder(TreeNode *root)
    {
        vector<int> preorder;
        if (root == NULL)
            return;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->data);
            if (root->right)
            {
                st.push(root->right);
            }
            if (root->left)
            {
                st.push(root->left);
            }
        }

        for (auto &it : preorder)
        {
            cout << it << " ";
        }
    }

    void iterativeInorder(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inOrder;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->data);
                node = node->right;
            }
        }
        for (auto &it : inOrder)
        {
            cout << it << " ";
        }
    }

    void iterativePostorder(TreeNode *root)
    {
        vector<int> postOrder;
        if (root == NULL)
            return;
        stack<TreeNode *> s1, s2;

        s1.push(root);

        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->left)
            {
                s1.push(root->left);
            }
            if (root->right)
            {
                s1.push(root->right);
            }
        }
        while (!s2.empty())
        {
            postOrder.push_back(s2.top()->data);
            s2.pop();
        }
        for (auto &it : postOrder)
        {
            cout << it << " ";
        }
    }

    void allInOne(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        vector<int> in, pre, post;
        if (root == NULL)
            return;

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();
            if (it.second == 1)
            {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->left)
                {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->right)
                {
                    st.push({it.first->right, 1});
                }
            }
            else
            {
                post.push_back(it.first->data);
            }
        }
        for (auto &it : in)
        {
            cout << it << " ";
        }
        cout << "\n";
        for (auto &it : pre)
        {
            cout << it << " ";
        }
        cout << "\n";
        for (auto &it : post)
        {
            cout << it << " ";
        }
    }

    int len(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = len(root->left);
        int rh = len(root->right);
        return 1 + max(lh, rh);
    }
};

int main()
{
    fast;

    // here root is a object 
    // TreeNode root;

    // pointer to a TreeNode
    TreeNode *root = new TreeNode(1);


    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // root->iterativePreorder(root);
    // cout << "\n";
    // root->iterativeInorder(root);
    // cout << "\n";
    // root->iterativePostorder(root);
    cout << "\n";
    root->allInOne(root);
    cout << "\n";
    root->len(root);
    // Clean up memory
    delete root;

    return 0;
}
