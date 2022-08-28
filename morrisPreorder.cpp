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

vector<int> morissPre(node *root)
{
    vector<int> ans;
    while (root != NULL)
    {
        if (root->left == NULL)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else{
            while (root -> left -> right != NULL && root -> left -> right != root){
                root -> left = root -> left -> right;
            }

            if(root -> left -> right == NULL){
                root -> left -> right = root;
                ans.push_back(root -> data);
                root = root -> left;
            }
            else{
                root -> left -> right = NULL;
                root = root -> right;
            }
        }
    }
    return ans;
}

int main()
{
    node* root = new node(2);
    root -> left = new node(3);
    root -> left -> right = new node(1);
    root -> right = new node(4);

    vector<int> ans = morissPre(root);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}