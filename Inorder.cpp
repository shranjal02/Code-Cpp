#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void traVerse(node *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }
    traVerse(root->left, ans);
    ans.push_back(root->data);
    traVerse(root->right, ans);
}

vector<int> inOrder(node *root)
{

    vector<int> ans;
    traVerse(root, ans);

    return ans;
}
