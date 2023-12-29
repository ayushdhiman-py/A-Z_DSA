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

    void Serialize(Node *root)
    {
        string s = "";
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *ele = q.front();
            q.pop();
            if (ele == NULL)
                s.append("#,");
            else
                s.append(to_string(ele->data) + ',');

            if (ele != NULL)
            {
                q.push(ele->left);
                q.push(ele->right);
            }
        }
        // cout << s << "\n";
        Node *newRoot = DeSerialize(s);
        levelOrderTraversal(newRoot);
        return;
    }

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

    Node *DeSerialize(string data)
    {
        queue<Node *> q;
        stringstream s(data);
        // below we took out the first element from the string
        string str;
        getline(s, str, ',');
        Node *root = new Node(stoi(str));
        q.push(root);

        while (!q.empty())
        {
            Node *ele = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                ele->left = NULL;
            }
            else
            {
                Node *leftNode = new Node(stoi(str));
                ele->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                ele->right = NULL;
            }
            else
            {
                Node *rightNode = new Node(stoi(str));
                ele->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main()
{
    fast;

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(13);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->Serialize(root);

    // Clean up memory
    delete root;

    return 0;
}

// string stream
// allows string to be iterated over as objects
//
// stringstream s(stringProvided)
// string str
// getline(s,str,',') <- will skip ',' and go to other things in stringProvided
